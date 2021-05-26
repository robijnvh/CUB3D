/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 11:36:30 by rvan-hou       #+#    #+#                */
/*   Updated: 2020/03/21 17:30:25 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		move_forward(t_vars *win, double move, double x, double y)
{
	win->data->start_x += 0.2 * sin(win->angle + (move * M_PI));
	if (win->map->array[(int)win->data->start_y]
	[(int)win->data->start_x] == '1')
	{
		win->data->start_x = x;
		win->data->start_y = y;
		return ;
	}
	win->data->start_y += 0.2 * cos(win->angle + (move * M_PI));
	if (win->map->array[(int)win->data->start_y]
	[(int)win->data->start_x] == '1')
	{
		win->data->start_x = x;
		win->data->start_y = y;
		return ;
	}
}

void		move_backwards(t_vars *win, double x, double y)
{
	win->data->start_x -= 0.2 * sin(win->angle);
	if (win->map->array[(int)win->data->start_y]
	[(int)win->data->start_x] == '1')
	{
		win->data->start_x = x;
		win->data->start_y = y;
		return ;
	}
	win->data->start_y -= 0.2 * cos(win->angle);
	if (win->map->array[(int)win->data->start_y]
	[(int)win->data->start_x] == '1')
	{
		win->data->start_x = x;
		win->data->start_y = y;
		return ;
	}
}

void		move_player(t_vars *win, double move, double rotate, int reverse)
{
	double	y;
	double	x;

	x = win->data->start_x;
	y = win->data->start_y;
	if (win->angle > 2 * M_PI)
		win->angle -= 2 * M_PI;
	if (win->angle <= 0 * M_PI)
		win->angle += 2 * M_PI;
	if (rotate != 0)
	{
		win->angle += (rotate * M_PI);
		return ;
	}
	if (reverse == 1)
		move_backwards(win, x, y);
	else
		move_forward(win, move, x, y);
}
