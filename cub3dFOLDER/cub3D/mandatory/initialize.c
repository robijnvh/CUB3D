/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 10:33:20 by rvan-hou       #+#    #+#                */
/*   Updated: 2020/03/21 12:01:24 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		return_error(char *s, int i)
{
	if (i == 0)
		write(1, "ERROR: ", 7);
	ft_putstr(s);
	return (i);
}

void	clear_all_data(t_vars *win)
{
	win->data->dist_x = 0;
	win->data->dist_y = 0;
	win->data->del_x = 0;
	win->data->del_y = 0;
	win->data->step_x = 1;
	win->data->step_y = 1;
	win->data->hit_x = 0;
	win->data->hit_y = 0;
	win->data->ray_length = 0.0;
	win->data->side = 0;
	win->data->perp_wall_dist = 0;
	win->data->sprite = 0;
	win->data->tex_hit = 0;
	win->data->tex_x = 0;
	win->data->tex_y = 0;
	win->data->tex_size = 0;
	win->data->first = 0;
	win->data->sp_angle_l = 0.0;
	win->data->sp_angle_r = 0.0;
	win->data->x = 0;
	win->data->y = 0;
	win->data->i = 0;
	win->on_wall = 0;
}

int		init_arguments(int argc, char **argv, t_data *data)
{
	if (argc < 2 || argc > 3)
		return (return_error("INCORRECT ARGUMENT\n", 0));
	if (!check_file(argv[1]))
		return (return_error("WRONG FILE\n", 0));
	else
		return_error("CORRECT FILE\n", 1);
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) == 6 && !ft_strncmp(argv[2], "--save", 6))
			data->save = 1;
		else
			return (return_error("INCORRECT ARGUMENT\n", 0));
	}
	return (1);
}

void	init_three_d_map(t_vars *win)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	win->og_rh = 0;
	win->og_rw = 0;
	win->og_rh = win->data->rh;
	win->og_rw = win->data->rw;
	win->mlx2 = mlx_init();
	mlx_get_screen_size(win->mlx2, &w, &h);
	if (win->data->rh > h)
		win->data->rh = h;
	if (win->data->rw > w)
		win->data->rw = w;
	win->win2 = mlx_new_window(win->mlx2, win->data->rw, win->data->rh,
	"3D MAP");
	win->img2 = mlx_new_image(win->mlx2, win->data->rw, win->data->rh);
	win->addr2 = mlx_get_data_addr(win->img2, &win->bits_per_pixel2,
	&win->line_length2, &win->endian2);
}
