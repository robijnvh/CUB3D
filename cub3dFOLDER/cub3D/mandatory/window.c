/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 10:42:14 by rvan-hou       #+#    #+#                */
/*   Updated: 2020/03/12 19:09:13 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_rays(t_vars *win)
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
		find_all_hits(win, win->angle);
		create_three_d_map(win, x, win->angle_tmp);
		check -= (1.0 / ((double)win->data->rw / 2.0));
		x++;
	}
	win->angle = win->angle_tmp;
}

int			press_key(int key, t_vars *win)
{
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
	set_rays(win);
	mlx_put_image_to_window(win->mlx2, win->win2, win->img2, 0, 0);
	return (key);
}

int			leave_window(t_vars *win)
{
	mlx_destroy_window(win->mlx2, win->win2);
	write(1, "GAME CLOSED\n", 12);
	exit(0);
	return (0);
}

int			display_map_window(t_data *data, t_map *map)
{
	t_vars		win;

	win.map = map;
	win.data = data;
	win.angle = 0.0;
	win.window_mid = win.data->rh / 2;
	win.data->mid = 1.0 / fabs(tan(1.0 / 6 * M_PI));
	win.data->step = 1.0 / 10000.0;
	if (!set_textures(&win))
		return (0);
	if (!set_sprite(&win))
		return (0);
	// sleep(3);
	init_three_d_map(&win);
	scan_map(data, &win);
	set_rays(&win);
	if (win.data->save == 1)
	{
		create_bmp("screenshot.bmp", win.addr2, data->rw, data->rh);
		return (0);
	}
	mlx_put_image_to_window(win.mlx2, win.win2, win.img2, 0, 0);
	mlx_hook(win.win2, 2, 1L << 0, press_key, &win);
	mlx_hook(win.win2, 17, 1L << 17, leave_window, &win);
	mlx_loop(win.mlx2);
	return (0);
}
