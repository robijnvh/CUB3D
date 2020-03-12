/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 12:51:55 by rvan-hou       #+#    #+#                */
/*   Updated: 2020/03/12 18:24:03 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strlen2(const char *str, int i)
{
	int len;

	len = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

void	find_max_columns(t_map *map, t_data *data, int i)
{
	while (map->str[i] != '\0')
	{
		data->columns_cut = ft_strlen2(map->str, i);
		if (data->columns_cut > data->max_columns)
			data->max_columns = data->columns_cut;
		while (map->str[i] != '\n' && map->str[i] != '\0')
			i++;
		if (map->str[i] == '\0')
			break ;
		i++;
	}
}

int		fill_array(t_map *map, t_data *data, int y, int *i)
{
	int	x;

	data->columns_cut = ft_strlen2(map->str, *i);
	map->array[y] = (char*)malloc(sizeof(char) * data->max_columns + 1);
	if (!map->array[y])
	{
		free_array(map->array, y);
		return (return_error("MALLOC FAIL\n", 0));
	}
	x = 0;
	while (x < data->columns_cut)
	{
		map->array[y][x] = map->str[*i];
		x++;
		*i += 1;
	}
	while (x < data->max_columns)
	{
		map->array[y][x] = ' ';
		x++;
	}
	map->array[y][data->max_columns] = '\0';
	return (1);
}

int		make_map(t_data *data, t_map *map, int i)
{
	int	y;

	y = 0;
	map->array = (char**)malloc(sizeof(char*) * map->rows);
	if (!map->array)
		return (return_error("MALLOC FAIL\n", 0));
	find_max_columns(map, data, i);
	while (y < map->rows)
	{
		if (!fill_array(map, data, y, &i))
			return (0);
		while (map->str[i] == '\n')
			i++;
		y++;
	}
	return (1);
}

int		makearray(t_data *data, t_map *map)
{
	int	i;

	i = (ft_strlen(map->str) - 1);
	while (map->str[i] != '\n')
	{
		i--;
		map->columns++;
	}
	i = (ft_strlen(map->str) - 1);
	while (check_char(map->str[i], map) &&
	(!(map->str[i] == '\n' && map->str[i + 1] == '\n')))
	{
		if (map->str[i] == '\n')
			map->rows++;
		i--;
	}
	// if (!(check_char(map->str[i], map)))
	// 	return (return_error("WRONG CHARACTER\n", 0));
	if (map->startpoint == 'X')
		return (return_error("MISSING STARTPOINT\n", 0));
	while (map->str[i] != '\n' && map->str[i] != '\0')
		i++;
	while (map->str[i] == '\n')
		i++;
	if (map->str[i] == '\0')
		return (0);
	return (make_map(data, map, i));
}
