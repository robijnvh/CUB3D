/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-hou <rvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:28:09 by rvan-hou          #+#    #+#             */
/*   Updated: 2020/03/12 16:11:45 by rvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_first_line(t_map *map, int y)
{
	int	x;

	x = 0;
	while (map->array[y][x] == ' ')
		x++;
	if (map->array[y][x] != '1')
		return (0);
	while (x < ft_strlen(map->array[y]))
	{
		if (map->array[y][x] == '1')
			x++;
		else if (map->array[y][x] == ' ' &&
		(map->array[y + 1][x] == ' ' || map->array[y + 1][x] == '1'))
			x++;
		else
			return (0);
	}
	return (1);
}

int		check_last_line(t_map *map, int y)
{
	int		x;

	x = 0;
	while (map->array[y][x] == ' ')
		x++;
	if (map->array[y][x] != '1')
		return (0);
	while (x < ft_strlen(map->array[y]) && map->array[y][x] != '\0')
	{
		if (map->array[y][x] == '1')
			x++;
		else if (map->array[y][x] == ' ' &&
		(map->array[y - 1][x] == ' ' || map->array[y - 1][x] == '1'))
			x++;
		else
			return (0);
	}
	return (1);
}

int		check_middle2(t_map *map, int y, int x)
{
	while (x < ft_strlen(map->array[y]))
	{
		if (map->array[y][x] == '1' || map->array[y][x] == '2'
		|| map->array[y][x] == 'N' || map->array[y][x] == 'S'
		|| map->array[y][x] == 'E' || map->array[y][x] == 'W'
		|| map->array[y][x] == '0')
			x++;
		else if (map->array[y][x] == ' ')
		{
			if (x < ft_strlen(map->array[y - 1]) &&
			!(map->array[y - 1][x] == ' ' || map->array[y - 1][x] == '1'))
				return (0);
			if (x < ft_strlen(map->array[y + 1]) &&
			!(map->array[y + 1][x] == ' ' || map->array[y + 1][x] == '1'))
				return (0);
			if (x - 1 < ft_strlen(map->array[y]) &&
			!(map->array[y][x - 1] == ' ' || map->array[y][x - 1] == '1'))
				return (0);
			if (x + 1 < ft_strlen(map->array[y]) &&
			!(map->array[y][x + 1] == ' ' || map->array[y][x + 1] == '1'))
				return (0);
			x++;
		}
		else
			return (0);
	}
	return (1);
}

int		check_middle(t_map *map, int y)
{
	int	x;

	x = 0;
	while (map->array[y][x] == ' ')
		x++;
	if (map->array[y][x] != '1')
		return (0);
	if (!check_middle2(map, y, x))
		return (0);
	x = ft_strlen(map->array[y]) - 1;
	while (map->array[y][x] == ' ')
		x--;
	if (map->array[y][x] != '1')
		return (0);
	return (1);
}

int		check_map(t_map *map, t_data *data)
{
	int	y;

	y = 0;
	while (y < map->rows)
	{
		if (y == 0)
		{
			if (!check_first_line(map, y))
				return (0);
		}
		if (y > 0 && y < map->rows - 1)
		{
			if (!check_middle(map, y))
				return (0);
		}
		if (y == map->rows - 1)
		{
			if (!check_last_line(map, y))
				return (0);
		}
		y++;
	}
	fill_spaces(map, data);
	return (1);
}
