/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smooth_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 10:08:58 by rvan-hou       #+#    #+#                */
/*   Updated: 2020/03/11 10:10:12 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		update(t_vars *win)
{
	if (win->m.rotate_l == 1)
		move_player(win, 0, 0.05, 0);
	if (win->m.rotate_r == 1)
		move_player(win, 0, -0.05, 0);
	if (win->m.move_l == 1)
		move_player(win, 0.5, 0, 0);
	if (win->m.move_r)
		move_player(win, -0.5, 0, 0);
	if (win->m.move_u == 1)
		move_player(win, 0, 0, 0);
	if (win->m.move_d == 1)
		move_player(win, 0, 0, 1);
	draw_rays(win);
	mlx_put_image_to_window(win->mlx2, win->win2, win->img2, 0, 0);
	return (0);
}

void	clear_move(t_vars *win)
{
	win->m.move_d = 0;
	win->m.move_l = 0;
	win->m.move_r = 0;
	win->m.move_u = 0;
	win->m.rotate_l = 0;
	win->m.rotate_r = 0;
}

int		keypress(int key, t_vars *win)
{
	if (key == ROTATE_LEFT_KEY)
		win->m.rotate_l = 1;
	if (key == ROTATE_RIGHT_KEY)
		win->m.rotate_r = 1;
	if (key == MOVE_LEFT_KEY)
		win->m.move_l = 1;
	if (key == MOVE_RIGHT_KEY)
		win->m.move_r = 1;
	if (key == MOVE_UP_KEY)
		win->m.move_u = 1;
	if (key == MOVE_DOWN_KEY)
		win->m.move_d = 1;
	if (key == ESC)
	{
		mlx_destroy_window(win->mlx, win->win);
		exit(0);
	}
	return (key);
}

int		keyrelease(int key, t_vars *win)
{
	if (key == ROTATE_LEFT_KEY)
		win->m.rotate_l = 0;
	if (key == ROTATE_RIGHT_KEY)
		win->m.rotate_r = 0;
	if (key == MOVE_LEFT_KEY)
		win->m.move_l = 0;
	if (key == MOVE_RIGHT_KEY)
		win->m.move_r = 0;
	if (key == MOVE_UP_KEY)
		win->m.move_u = 0;
	if (key == MOVE_DOWN_KEY)
		win->m.move_d = 0;
	return (key);
}
