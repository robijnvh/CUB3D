/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 15:01:31 by rvan-hou       #+#    #+#                */
/*   Updated: 2020/03/13 14:40:24 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_three_d_map(t_vars *win, double x, double tmp)
{
	double	size;
	int		i;

	i = 0;
	win->data->perp_wall_dist = (cos(tmp - win->angle) * win->data->ray_length);
	size = (1.0 / win->data->perp_wall_dist) * win->window_mid;
	if (size > win->window_mid)
		size = win->window_mid;
	put_texture(win, x, size);
	while (win->data->sprite == 1 && win->data->i > 0)
	{
		if (win->data->on_wall_sprite[win->data->i - 1] != -1)
		{
			win->data->x = win->data->spritehit[win->data->i - 1];
			make_sprite(win, win->data->x,
			win->data->on_wall_sprite[win->data->i - 1], x);
		}
		win->data->i--;
	}
}

void	find_ray_length3(t_vars *win)
{
	if (win->map->array[(int)win->data->y]
	[(int)win->data->x] == '2' && win->data->first == 0)
	{
		win->data->sprite = 1;
		hit_sprite_y(win);
		win->data->spritehit[win->data->i] = 1.0 /
		(sqrt((pow(win->data->start_x - ((int)win->data->x + 0.5), 2) +
		pow(win->data->start_y - ((int)win->data->y + 0.5), 2))) *
		cos(win->angle_tmp - win->angle));
		win->data->first = 1;
	}
	if (win->data->first != 0 && win->data->i < 10)
	{
		win->data->first = 0;
		win->data->i++;
	}
	win->data->hit_y += win->data->del_y;
}

void	find_ray_length2(t_vars *win)
{
	if (win->map->array[(int)win->data->y]
	[(int)win->data->x] == '2' && win->data->first == 0)
	{
		win->data->sprite = 1;
		hit_sprite_x(win);
		win->data->spritehit[win->data->i] = 1.0 /
		(sqrt((pow(win->data->start_x - ((int)win->data->x + 0.5), 2) +
		pow(win->data->start_y - ((int)win->data->y + 0.5), 2))) *
		cos(win->angle_tmp - win->angle));
		win->data->first = 1;
	}
	if (win->data->first != 0 && win->data->i < 10)
	{
		win->data->first = 0;
		win->data->i++;
	}
	win->data->hit_x += win->data->del_x;
}

void	find_ray_length(t_vars *win)
{
	win->data->y = win->data->start_y;
	win->data->x = win->data->start_x;
	while (1)
	{
		if (win->data->hit_x < win->data->hit_y)
		{
			win->data->side = 1;
			win->data->x += win->data->step_x;
			if (win->map->array[(int)win->data->y][(int)win->data->x] == '1')
				break ;
			find_ray_length2(win);
		}
		else
		{
			win->data->side = 0;
			win->data->y += win->data->step_y;
			if (win->map->array[(int)win->data->y][(int)win->data->x] == '1')
				break ;
			find_ray_length3(win);
		}
	}
	if (win->data->side == 1)
		win->data->ray_length = win->data->hit_x;
	else
		win->data->ray_length = win->data->hit_y;
}

void	find_all_hits(t_vars *win, double tmp)
{
	clear_all_data(win);
	win->data->del_x = fabs(1 / sin(tmp));
	win->data->del_y = fabs(1 / cos(tmp));
	if (tmp >= 0 * M_PI && tmp < 1 * M_PI)
		win->data->dist_x = 1 - (win->data->start_x - (int)win->data->start_x);
	else
	{
		win->data->dist_x = win->data->start_x - (int)win->data->start_x;
		win->data->step_x = -1;
	}
	if (tmp >= 0.5 * M_PI && tmp <= 1.5 * M_PI)
	{
		win->data->dist_y = win->data->start_y - (int)win->data->start_y;
		win->data->step_y = -1;
	}
	else
		win->data->dist_y = 1 - (win->data->start_y - (int)win->data->start_y);
	win->data->hit_x = win->data->dist_x * win->data->del_x;
	win->data->hit_y = win->data->dist_y * win->data->del_y;
	find_ray_length(win);
}
