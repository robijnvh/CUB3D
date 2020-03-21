/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scan_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:51:44 by rvan-hou       #+#    #+#                */
/*   Updated: 2020/03/13 15:35:18 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_all_lines(char *s, int end)
{
	int i;

	i = 0;
	while (i < end)
	{
		if (s[i] == 'R' || s[i] == 'N' || s[i] == 'S'
		|| s[i] == 'W' || s[i] == 'E' || s[i] == 'F'
		|| s[i] == 'C')
		{
			while (s[i] != '\n')
				i++;
			i++;
		}
		else if (s[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int			check_file_type(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == 'g')
		return (1);
	return (0);
}

void		set_orientation(char c, t_vars *win, int x, int y)
{
	win->data->start_x = (double)x + 0.5;
	win->data->start_y = (double)y + 0.5;
	if (c == 'N')
		win->angle = 1 * M_PI;
	if (c == 'E')
		win->angle = 0.5 * M_PI;
	if (c == 'S')
		win->angle = 2 * M_PI;
	if (c == 'W')
		win->angle = 1.5 * M_PI;
}

int			scan_map(t_data *data, t_vars *win)
{
	int		y;
	int		x;

	y = 0;
	data->sqr_h = data->rh / win->map->rows;
	data->sqr_w = data->rw / data->max_columns;
	if (data->sqr_w < data->sqr_h)
		data->sqr_h = data->sqr_w;
	else
		data->sqr_w = data->sqr_h;
	while (y < win->map->rows)
	{
		x = 0;
		while (x < data->max_columns)
		{
			if (ft_strchr("SWEN", win->map->array[y][x]) > 0)
			{
				data->orientation = win->map->array[y][x];
				set_orientation(data->orientation, win, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
