/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapf_not_needed.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 10:08:10 by rvan-hou       #+#    #+#                */
/*   Updated: 2020/03/11 16:32:03 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		del_rays(t_vars *win)
{
	int		i;
	double	check;
	double	x;

	win->angle_tmp = win->angle;
	x = 0;
	check = 1;
	while (check >= -1)
	{
		i = 0;
		win->angle = win->angle_tmp + atan(check / win->data->mid);
		if (win->angle > 2 * M_PI)
			win->angle -= 2 * M_PI;
		if (win->angle <= 0 * M_PI)
			win->angle += 2 * M_PI;
		while (my_mlx_pixel_put_rays(win, ((win->data->start_x) * win->data->sqr_w) + sin(win->angle)
		* (double)i, (win->data->start_y * win->data->sqr_h) + cos(win->angle) * (double)i, win->map->td_map_floor))
			i++;
		check -= (1.0 / ((double)win->data->rw / 2.0));
		x++;
	}
	win->angle = win->angle_tmp;
}

int			vertical(int x, int y, int max, t_vars *win)
{
	int	i;

	i = 0;
	while (y + i < max)
	{
		my_mlx_pixel_put(win, x, y + i, win->map->td_map_wall);
		i++;
	}
	return (0);
}

int			horizontal(int max, int x, int y, t_vars *win)
{
	int	i;

	i = 0;
	while (x + i < max)
	{
		my_mlx_pixel_put(win, x + i, y, win->map->td_map_wall);
		i++;
	}
	return (0);
}

int			add_grid(t_vars *win)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	x = 0;
	while (i < win->data->rw)
	{
		vertical(i, y, win->data->rh, win);
		i = i + (win->data->sqr_w);
	}
	i = 0;
	while (i < win->data->rh)
	{
		horizontal(win->data->rw, x, i, win);
		i = i + (win->data->sqr_h);
	}
	return (0);
}

int			draw_square(double x, double y, int color, t_vars *win)
{
	double i;
	double j;

	i = x;
	j = y;
	while (i < win->data->sqr_w + x)
	{
		j = y;
		while (j < win->data->sqr_h + y)
		{
			my_mlx_pixel_put(win, i, j, color);
			j++;
		}
		i++;
	}
	return (0);
}

int			draw_map(t_data *data, t_vars *win)
{
	int		y;
	int		x;
	double	i;
	double	j;

	y = 0;
	j = 0;
	data->sqr_h = data->rh / win->map->rows;
	data->sqr_w = data->rw / data->max_columns;
	if (data->sqr_w < data->sqr_h)
		data->sqr_h = data->sqr_w;
	else
		data->sqr_w = data->sqr_h;
	while (y < win->map->rows)
	{
		x = 0;
		i = 0;
		while (x < data->max_columns)
		{
			if (win->map->array[y][x] == '1')
				draw_square(i, j, win->map->td_map_wall, win);
			if (win->map->array[y][x] == '0')
				draw_square(i, j, win->map->td_map_floor, win);
			if (ft_strchr("SWEN", win->map->array[y][x]) > 0)
			{
				draw_square(i, j, win->map->td_map_floor, win);
				data->orientation = win->map->array[y][x];
				win->data->start_x = (double)x + 0.5;
				win->data->start_y = (double)y + 0.5;
				set_orientation(data->orientation, win, x, y);
			}
			if (win->map->array[y][x] == '2')
				draw_square(i, j, 0x00005100, win);
			x++;
			i = i + data->sqr_w;
		}
		y++;
		j = j + data->sqr_h;
	}
	return (0);
}

void		my_mlx_pixel_put(t_vars *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			my_mlx_pixel_put_rays(t_vars *win, int x, int y, int color)
{
	char	*dst;

	if (win->map->array[y / (int)win->data->sqr_h]
	[x / (int)win->data->sqr_w] == '1' || win->map->array[y /
	(int)win->data->sqr_h][x / (int)win->data->sqr_w] == '2')
		return (0);
	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	return (1);
}

void	init_two_d_map(t_vars *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->data->rw, win->data->rh, "2D MAP");
	win->img = mlx_new_image(win->mlx, win->data->rw, win->data->rh);
	win->addr = mlx_get_data_addr(win->img, &win->bits_per_pixel,
	&win->line_length, &win->endian);
	win->map->td_map_floor = 0x005E5C62;
	win->map->td_map_wall = 0x000E1770;
}

void		set_rays(t_vars *win)
{
	int	i;
	double	check;
	double	x;

	win->angle_tmp = win->angle;
	x = 0;
	check = 1;
	while (check >= -1)
	{
		i = 0;
		win->angle = win->angle_tmp + atan(check / win->data->mid);
		if (win->angle > 2 * M_PI)
			win->angle -= 2 * M_PI;
		if (win->angle <= 0 * M_PI)
			win->angle += 2 * M_PI;
		// while (my_mlx_pixel_put_rays(win, ((win->data->start_x) * win->data->sqr_w) + (sin(win->angle)
		// * (double)i), (win->data->start_y * win->data->sqr_h) + cos(win->angle) * (double)i, 0x00FFFFFF))
		// 	i++;
		find_all_hits(win, win->angle);
		create_three_d_map(win, x, win->angle_tmp);
		check -= (1.0 / ((double)win->data->rw / 2.0));
		x++;
		// check = -2;
	}
	win->angle = win->angle_tmp;
}

int			press_key(int key, t_vars *win)
{
	win->count++;
	// del_rays(win);
	if (key == ROTATE_LEFT_KEY)
		move_player(win, 0, 0.01, 0);
	if (key == ROTATE_RIGHT_KEY)
		move_player(win, 0, -0.01, 0);
	if (key == MOVE_LEFT_KEY)
		move_player(win, 0.5, 0, 0);
	if (key == MOVE_RIGHT_KEY)
		move_player(win, -0.5, 0, 0);
	if (key == MOVE_UP_KEY)
		move_player(win, 0, 0, 0);
	if (key == MOVE_DOWN_KEY)
		move_player(win, 0, 0, 1);
	if (key == ESC)
	{
		mlx_destroy_window(win->mlx, win->win);
		exit(0);
	}
	// add_grid(win);
	set_rays(win);
	// mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	mlx_put_image_to_window(win->mlx2, win->win2, win->img2, 0, 0);
	return (key);
}

void		display_map_window(t_data *data, t_map *map)
{
	t_vars		win;

	win.map = map;
	win.data = data;
	win.angle = 0.0;
	win.window_mid = win.data->rh / 2;
	win.data->mid = 1.0 / fabs(tan(1.0 / 6 * M_PI));
	win.data->step = 1.0 / 10000.0;
	win.count = 0;
	set_textures(&win);
	set_sprite(&win);
	init_three_d_map(&win);
	scan_map(data, &win);
	set_rays(&win);
	if (win.data->save == 1)
	{
		create_bmp("screenshot.bmp", win.addr2, data->rw, data->rh);
		return ;
	}
	mlx_put_image_to_window(win.mlx2, win.win2, win.img2, 0, 0);
	mlx_hook(win.win2, 2, 1L << 0, press_key, &win);
	// clear_move(&win);
	// sleep(1);
	mlx_hook(win.win2, 17, 1L << 17, leave_window, &win);
	// mlx_hook(win.win2, 2, 1L << 0, keypress, &win);
	// mlx_hook(win.win2, 3, 1L << 1, keyrelease, &win);
	// mlx_loop_hook(win.mlx2, update, &win);
	// mlx_loop(win.mlx);
	mlx_loop(win.mlx2);
}