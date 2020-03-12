/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-hou <rvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:31:06 by rvan-hou          #+#    #+#             */
/*   Updated: 2020/03/11 16:29:40 by rvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_angle(t_vars *win)
{
	win->data->sp_angle_l = win->angle + 0.5 * M_PI;
	if (win->data->sp_angle_l > 2 * M_PI)
		win->data->sp_angle_l -= 2 * M_PI;
	win->data->sp_angle_r = win->angle - 0.5 * M_PI;
	if (win->data->sp_angle_r < 0 * M_PI)
		win->data->sp_angle_r += 2 * M_PI;
}

void		hit_sprite_y(t_vars *win)
{
	init_angle(win);
	win->on_wall = fabs(sin(win->angle) * win->data->hit_y) - win->data->dist_x;
	win->on_wall = win->on_wall - (int)win->on_wall;
	if (win->on_wall < 0)
		win->on_wall = win->on_wall + 1.0;
	if (win->data->step_y == -1)
	{
		if (win->angle > M_PI)
		{
			win->on_wall = 1 - win->on_wall;
			find_intersect_y(win, -1, 1, win->data->step);
		}
		else
			find_intersect_y(win, 1, 1, win->data->step);
	}
	else if (win->data->step_y == 1)
	{
		if (win->angle < 0.5 * M_PI)
		{
			win->on_wall = 1 - win->on_wall;
			find_intersect_y(win, -1, -1, win->data->step);
		}
		else
			find_intersect_y(win, 1, -1, win->data->step);
	}
}

void		hit_sprite_x(t_vars *win)
{
	init_angle(win);
	win->on_wall = fabs(cos(win->angle) * win->data->hit_x) - win->data->dist_y;
	win->on_wall = win->on_wall - (int)win->on_wall;
	if (win->on_wall < 0)
		win->on_wall = win->on_wall + 1.0;
	if (win->data->step_x == -1)
	{
		if (win->angle > 1.5 * M_PI && win->angle <= 2 * M_PI)
		{
			win->on_wall = 1 - win->on_wall;
			find_intersect_x(win, -0.5, 0, win->data->step);
		}
		else
			find_intersect_x(win, 0.5, 0, win->data->step);
	}
	if (win->data->step_x == 1)
	{
		if (win->angle < 0.5 * M_PI)
		{
			win->on_wall = 1 - win->on_wall;
			find_intersect_x(win, -0.5, 1, win->data->step);
		}
		else
			find_intersect_x(win, 0.5, 1, win->data->step);
	}
}
