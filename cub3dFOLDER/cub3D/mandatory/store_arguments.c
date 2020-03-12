/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-hou <rvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:06:42 by rvan-hou          #+#    #+#             */
/*   Updated: 2020/03/12 15:11:09 by rvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		store_path(char *buf, t_data *data, char c)
{
	while (*buf != '.')
		buf++;
	if (!check_double(data, c))
		return (return_error("DOUBLE TEXTURE\n", 0));
	if (c == 'N')
		data->no = ft_strdup(buf);
	if (c == 'S')
		data->so = ft_strdup(buf);
	if (c == 'W')
		data->we = ft_strdup(buf);
	if (c == 'E')
		data->ea = ft_strdup(buf);
	if (c == 's')
		data->s = ft_strdup(buf);
	return (1);
}

int		floor_to_color(char *buf, t_data *data)
{
	int	i;

	i = 0;
	i++;
	data->fred = ft_atoi(&buf[i]);
	while (buf[i] != ',' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
		return (0);
	i++;
	data->fgreen = ft_atoi(&buf[i]);
	while (buf[i] != ',' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
		return (0);
	i++;
	data->fblue = ft_atoi(&buf[i]);
	while (buf[i] != ',' && buf[i] != '\0' && buf[i] != ' ' && buf[i] != '\n')
		i++;
	if (buf[i] != '\0')
		return (0);
	i = 0;
	if (data->fred < 0 || data->fred > 255)
		return (0);
	data->floor = data->floor | (data->fred << (16 - (i++ * 8)));
	if (data->fgreen < 0 || data->fgreen > 255)
		return (0);
	data->floor = data->floor | (data->fgreen << (16 - (i++ * 8)));
	if (data->fblue < 0 || data->fblue > 255)
		return (0);
	data->floor = data->floor | (data->fblue << (16 - (i++ * 8)));
	return (1);
}

int		ceiling_to_color(char *buf, t_data *data)
{
	int	i;

	i = 0;
	i++;
	data->cred = ft_atoi(&buf[i]);
	while (buf[i] != ',' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
		return (0);
	i++;
	data->cgreen = ft_atoi(&buf[i]);
	while (buf[i] != ',' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
		return (0);
	i++;
	data->cblue = ft_atoi(&buf[i]);
	while (buf[i] != ',' && buf[i] != '\0' && buf[i] != ' ' && buf[i] != '\n')
		i++;
	if (buf[i] != '\0')
		return (0);
	i = 0;
	if (data->cred < 0 || data->cred > 255)
		return (0);
	data->ceiling = data->ceiling | (data->cred << (16 - (i++ * 8)));
	if (data->cgreen < 0 || data->cgreen > 255)
		return (0);
	data->ceiling = data->ceiling | (data->cgreen << (16 - (i++ * 8)));
	if (data->cblue < 0 || data->cblue > 255)
		return (0);
	data->ceiling = data->ceiling | (data->cblue << (16 - (i++ * 8)));
	return (1);
}

int		get_resolution(char *buf, t_data *data)
{
	int i;

	i = 0;
	while (buf[i] == 'R' || buf[i] == ' ')
		i++;
	data->rw = ft_atoi(&buf[i]);
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	while (buf[i] == ' ')
		i++;
	if (buf[i] < '0' || buf[i] > '9')
		return (return_error("MISSING RESOLUTION\n", 0));
	data->rh = ft_atoi(&buf[i]);
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	if (buf[i] != '\0')
		return (return_error("INVAlID RESOLUTION\n", 0));
	if (data->rw > 3200)
		data->rw = 3200;
	if (data->rw < 50)
		data->rw = 50;
	if (data->rw == 650)
		data->rw = 649;
	if (data->rh > 1800)
		data->rh = 1800;
	if (data->rh < 50)
		data->rh = 50;
	if (data->rh % 2 != 0 && data->rh != 650)
		data->rh++;
	return (1);
}

int		store_arguments(char *buf, t_data *data)
{
	if (buf[0] == 'R')
		return (get_resolution(buf, data));
	else if (buf[0] == 'N')
		return (store_path(buf, data, 'N'));
	else if (buf[0] == 'S' && buf[1] == 'O')
		return (store_path(buf, data, 'S'));
	else if (buf[0] == 'W')
		return (store_path(buf, data, 'W'));
	else if (buf[0] == 'E')
		return (store_path(buf, data, 'E'));
	else if (buf[0] == 'S' && buf[1] != 'O')
		return (store_path(buf, data, 's'));
	else if (buf[0] == 'F')
	{
		if (!floor_to_color(buf, data))
			return (return_error("WRONG COLOR DATA\n", 0));
	}
	else if (buf[0] == 'C')
	{
		if (!ceiling_to_color(buf, data))
			return (return_error("WRONG COLOR DATA\n", 0));
	}
	else if (buf[0] == '\n' || buf[0] == '\0' || buf[0] == '1' ||
	buf[0] == ' ' || buf[0] == '0' || buf[0] == '2')
		return (1);
	else
		return (return_error("WRONG DATA IN FILE\n", 0));
	return (1);
}
