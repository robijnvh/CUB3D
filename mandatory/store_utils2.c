/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_utils2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/13 13:55:00 by rvan-hou      #+#    #+#                 */
/*   Updated: 2020/04/14 13:57:21 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_between(char *buf, int *i)
{
	while (buf[*i] == ' ')
		(*i)++;
	if (buf[*i] != ',')
		return (0);
	(*i)++;
	while (buf[*i] == ' ')
		(*i)++;
	if (buf[*i] < '0' || buf[*i] > '9')
		return (0);
	return (1);
}

int		get_color_data2(char *buf, t_data *data)
{
	int	i;

	i = 0;
	i++;
	while (buf[i] == ' ')
		i++;
	data->fred = ft_atoi(&buf[i]);
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	if (!check_between(buf, &i))
		return (0);
	data->fgreen = ft_atoi(&buf[i]);
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	if (!check_between(buf, &i))
		return (0);
	data->fblue = ft_atoi(&buf[i]);
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	while (buf[i] == ' ')
		i++;
	if (buf[i] != '\0')
		return (0);
	return (1);
}

int		get_color_data(char *buf, t_data *data)
{
	int	i;

	i = 0;
	i++;
	while (buf[i] == ' ')
		i++;
	data->cred = ft_atoi(&buf[i]);
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	if (!check_between(buf, &i))
		return (0);
	data->cgreen = ft_atoi(&buf[i]);
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	if (!check_between(buf, &i))
		return (0);
	data->cblue = ft_atoi(&buf[i]);
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	while (buf[i] == ' ')
		i++;
	if (buf[i] != '\0')
		return (0);
	return (1);
}

void	check_res_size(t_data *data)
{
	if (data->rw < 50)
	{
		data->rw = 50;
		write(1, "RESOLUTION WIDTH TOO SMALL, CORRECTED TO 50\n", 44);
	}
	if (data->rh < 50)
	{
		data->rh = 50;
		write(1, "RESOLUTION HEIGHT TOO SMALL, CORRECTED TO 50\n", 45);
	}
}
