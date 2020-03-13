/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-hou <rvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:00:49 by rvan-hou          #+#    #+#             */
/*   Updated: 2020/03/13 11:03:10 by rvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_floor(t_vars *win, int i, double x1)
{
	i += win->window_mid;
	while (i < win->data->rh)
	{
		my_mlx_pixel_put2(win, x1, i, win->data->floor);
		i++;
	}
}

void	set_ceiling(t_vars *win, int i, double x1)
{
	while ((win->window_mid - i) >= 0)
	{
		my_mlx_pixel_put2(win, x1, win->window_mid - i, win->data->ceiling);
		i++;
	}
}

void	my_mlx_pixel_put2(t_vars *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr2 + (y * win->line_length2 + x * (win->bits_per_pixel2 / 8));
	*(unsigned int*)dst = color;
}
