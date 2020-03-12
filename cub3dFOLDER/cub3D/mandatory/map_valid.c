/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_valid.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 12:54:10 by rvan-hou       #+#    #+#                */
/*   Updated: 2020/03/12 18:16:36 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_spaces(t_map *map, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < data->max_columns)
		{
			if (map->array[y][x] == ' ')
				map->array[y][x] = '1';
			x++;
		}
		y++;
	}
}

char	**free_array(char **str, int i)
{
	while (str)
	{
		free((void *)&str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

int		arguments_complete(t_data *data)
{
	if (!data->rw || !data->rh)
	{
		write(1, "MISSING RESOLUTION\n", 19);
		return (0);
	}
	if (!data->no || !data->so || !data->we || !data->s)
	{
		write(1, "MISSING TEXTURE/TEXTURES\n", 25);
		return (0);
	}
	if (!data->floor || !data->ceiling)
	{
		write(1, "MISSING FLOOR/CEILING COLOR\n", 28);
		return (0);
	}
	if (data->fred == -1 || data->fgreen == -1 || data->fblue == -1)
		return (0);
	if (data->cred == -1 || data->cgreen == -1 || data->cblue == -1)
		return (0);
	return (1);
}

int		check_char(char c, t_map *map)
{
	if (c >= '0' && c <= '2')
		return (1);
	if (c == ' ')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (map->startpoint == 'X')
			map->startpoint = c;
		else
			return (0);
		return (1);
	}
	if (c == '\n')
		return (1);
	return (0);
}
