/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_arguments.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 14:06:42 by rvan-hou      #+#    #+#                 */
/*   Updated: 2020/04/14 13:54:32 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		store_path(char *buf, t_data *data, char c)
{
	buf++;
	if (c != 's')
		buf++;
	while (*buf != '.')
	{
		if (*buf != ' ')
			return (return_error("WRONG CHARACTER IN PATH\n", 0));
		buf++;
	}
	if (!check_double(data, c))
		return (return_error("DOUBLE TEXTURE\n", 0));
	if (c == 'N')
		data->no = ft_strdup2(buf);
	if (c == 'S')
		data->so = ft_strdup2(buf);
	if (c == 'W')
		data->we = ft_strdup2(buf);
	if (c == 'E')
		data->ea = ft_strdup2(buf);
	if (c == 's')
		data->s = ft_strdup2(buf);
	return (1);
}

int		floor_to_color(char *buf, t_data *data)
{
	if (data->floor_check != 0)
		return (return_error("DOUBLE COLOR DATA\n", 0));
	data->floor_check = 1;
	if (!get_color_data2(buf, data))
		return (return_error("WRONG COLOR DATA\n", 0));
	if (data->fblue < 0 || data->fblue > 255)
		return (-1);
	if (data->fgreen < 0 || data->fgreen > 255)
		return (-1);
	if (data->fred < 0 || data->fred > 255)
		return (-1);
	data->floor = data->floor + data->fblue % 16 * pow(16, 0);
	data->floor = data->floor + data->fblue / 16 * pow(16, 1);
	data->floor = data->floor + data->fgreen % 16 * pow(16, 2);
	data->floor = data->floor + data->fgreen / 16 * pow(16, 3);
	data->floor = data->floor + data->fred % 16 * pow(16, 4);
	data->floor = data->floor + data->fred / 16 * pow(16, 5);
	return (1);
}

int		ceiling_to_color(char *buf, t_data *data)
{
	if (data->ceiling_check != 0)
		return (return_error("DOUBLE COLOR DATA\n", 0));
	data->ceiling_check = 1;
	if (!get_color_data(buf, data))
		return (return_error("WRONG COLOR DATA\n", 0));
	if (data->cblue < 0 || data->cblue > 255)
		return (-1);
	if (data->cgreen < 0 || data->cgreen > 255)
		return (-1);
	if (data->cred < 0 || data->cred > 255)
		return (-1);
	data->ceiling = data->ceiling + data->cblue % 16;
	data->ceiling = data->ceiling + data->cblue / 16 * 16;
	data->ceiling = data->ceiling + data->cgreen % 16 * pow(16, 2);
	data->ceiling = data->ceiling + data->cgreen / 16 * pow(16, 3);
	data->ceiling = data->ceiling + data->cred % 16 * pow(16, 4);
	data->ceiling = data->ceiling + data->cred / 16 * pow(16, 5);
	return (1);
}

int		get_resolution(char *buf, t_data *data)
{
	int i;

	i = 0;
	if (data->res_check != 0)
		return (return_error("DOUBLE RESOLUTION\n", 0));
	data->res_check = 1;
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
	while (buf[i] == ' ')
		i++;
	if (buf[i] != '\0')
		return (return_error("INVAlID RESOLUTION\n", 0));
	check_res_size(data);
	return (1);
}

int		store_arguments(char *buf, t_data *data)
{
	if (buf[0] == 'R')
		return (get_resolution(buf, data));
	else if (buf[0] == 'N' && buf[1] == 'O')
		return (store_path(buf, data, 'N'));
	else if (buf[0] == 'S' && buf[1] == 'O')
		return (store_path(buf, data, 'S'));
	else if (buf[0] == 'W' && buf[1] == 'E')
		return (store_path(buf, data, 'W'));
	else if (buf[0] == 'E' && buf[1] == 'A')
		return (store_path(buf, data, 'E'));
	else if (buf[0] == 'S' && buf[1] != 'O')
		return (store_path(buf, data, 's'));
	else if (buf[0] == 'F')
		return (floor_to_color(buf, data));
	else if (buf[0] == 'C')
		return (ceiling_to_color(buf, data));
	else if (buf[0] == '\n' || buf[0] == '\0' || buf[0] == '1' ||
	buf[0] == ' ' || buf[0] == '0' || buf[0] == '2')
		return (1);
	else
		return (return_error("WRONG DATA IN FILE\n", 0));
	return (1);
}
