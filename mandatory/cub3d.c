/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 13:51:28 by rvan-hou      #+#    #+#                 */
/*   Updated: 2020/04/14 14:08:08 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		makestring(int fd, t_map *map)
{
	char	*buf;
	int		ret;
	char	*tmp;

	map->str = ft_strdup("");
	if (!map->str)
		return (0);
	ret = 1;
	while (ret > 0)
	{
		buf = (char *)malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (0);
		buf[ret] = '\0';
		tmp = map->str;
		map->str = ft_strjoin((const char *)map->str, buf);
		free(tmp);
		free(buf);
		if (!map->str)
			return (0);
	}
	return (1);
}

int		set_arguments(int fd, t_data *data)
{
	char	*buf;

	close(fd);
	fd = open(data->input, O_RDONLY);
	while ((get_next_line(fd, &buf)) > 0)
	{
		if (!store_arguments(buf, data))
		{
			free(buf);
			return (0);
		}
		free(buf);
	}
	free(buf);
	if (!arguments_complete(data))
		return (0);
	return (1);
}

int		get_arguments(int fd, t_map *map, t_data *data)
{
	if (makestring(fd, map) == 0)
		return (return_error("READ FAIL\n", 0));
	if (makearray(data, map) == 0)
		return (return_error("WRONG MAP\n", 0));
	if (check_map(map, data) == 0)
		return (return_error("WRONG MAP\n", 0));
	if (set_arguments(fd, data) == 0)
		return (0);
	close(fd);
	return (1);
}

int		check_file(char *str)
{
	int	i;
	int	check;

	i = ft_strlen(str);
	check = 0;
	if (str[i - 1] != 'b')
		return (0);
	if (str[i - 2] != 'u')
		return (0);
	if (str[i - 3] != 'c')
		return (0);
	if (str[i - 4] != '.')
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_map	map;
	t_data	data;

	data.save = 0;
	if (!init_arguments(argc, argv, &data))
		return (0);
	clear_data_map(&data, &map);
	data.input = argv[1];
	fd = open(argv[1], O_RDONLY);
	if (get_arguments(fd, &map, &data) == 0)
	{
		free(map.str);
		return (return_error("MAP NOT VALID\n", 0));
	}
	else
		return_error("MAP VALID\n", 1);
	free(map.str);
	display_map_window(&data, &map);
	return (0);
}
