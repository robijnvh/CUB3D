/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 13:22:55 by rvan-hou       #+#    #+#                */
/*   Updated: 2020/03/11 11:28:11 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

int				check_eof(int ret)
{
	if (ret == 0)
		return (1);
	return (0);
}

char			*ft_newbuf(int const fd, char *buf, int *ret)
{
	char	*s;
	char	*tmp;

	s = (char *)malloc(sizeof(*s) * (BUFFER_SIZE + 1));
	if (!s)
		return (0);
	*ret = read(fd, s, BUFFER_SIZE);
	if (*ret == -1)
		return (0);
	if (*ret == 0 && s[*ret - 1] != '\n')
	{
		s[*ret] = '\n';
		s[*ret + 1] = '\0';
	}
	else
		s[*ret] = '\0';
	tmp = buf;
	buf = ft_strjoin_gnl(buf, s);
	free(tmp);
	free(s);
	return (buf);
}

int				makeline(char *buf, char *ptr, char **line, int ret)
{
	*ptr = '\0';
	*line = ft_strdup(buf);
	if (!*line)
		return (-1);
	ft_memmove(buf, ptr + 1, ft_strlen(ptr + 1) + 1);
	if (check_eof(ret) != 0 && buf[0] == '\0')
		return (0);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char		*buf;
	int				ret;

	if (line == NULL || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!buf)
		buf = ft_strdup("");
	ret = 1;
	while (ret)
	{
		if (ft_strchr(buf, '\n') != NULL)
			return (makeline(buf, ft_strchr(buf, '\n'), line, ret));
		buf = ft_newbuf(fd, buf, &ret);
		if (!buf)
			return (-1);
	}
	if (ret == 0)
	{
		*line = ft_strdup(buf);
		free(buf);
	}
	if (ret < 0)
		return (-1);
	return (ret);
}
