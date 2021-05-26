/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 11:39:01 by rvan-hou      #+#    #+#                 */
/*   Updated: 2020/04/14 13:28:57 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_double(t_data *data, char c)
{
	if (c == 'N' && data->no != NULL)
		return (0);
	if (c == 'S' && data->so != NULL)
		return (0);
	if (c == 'W' && data->we != NULL)
		return (0);
	if (c == 'E' && data->ea != NULL)
		return (0);
	if (c == 's' && data->s != NULL)
		return (0);
	return (1);
}

void	free_full_array(t_map *map)
{
	int i;

	i = 0;
	while (i < map->rows)
	{
		free(map->array[i]);
		i++;
	}
	free(map->array);
}

void	clear_data_map2(t_data *data, t_map *map)
{
	data->ceiling_check = 0;
	data->floor_check = 0;
	data->res_check = 0;
	data->columns_cut = 0;
	data->orientation = '.';
	data->sqr_h = 0;
	data->sqr_w = 0;
	data->start_x = 0;
	data->start_y = 0;
	map->str = NULL;
	map->rows = 0;
	map->columns = 0;
	map->startpoint = 'X';
	map->array = NULL;
}

void	clear_data_map(t_data *data, t_map *map)
{
	data->max_columns = 0;
	data->png = 0;
	data->input = NULL;
	data->rw = 0;
	data->rh = 0;
	data->no = NULL;
	data->ea = NULL;
	data->so = NULL;
	data->we = NULL;
	data->s = NULL;
	data->floor = 0;
	data->ceiling = 0;
	data->fred = -1;
	data->fgreen = -1;
	data->fblue = -1;
	data->cred = -1;
	data->cgreen = -1;
	data->cblue = -1;
	data->valid = 0;
	clear_data_map2(data, map);
}
