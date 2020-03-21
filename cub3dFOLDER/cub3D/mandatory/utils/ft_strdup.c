/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:12:13 by rvan-hou       #+#    #+#                */
/*   Updated: 2020/03/13 15:06:55 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>

int		check_for_spaces(const char *src, int i)
{
	while (src[i] == ' ')
		i++;
	if (src[i] != '\0')
		return (0);
	return (1);
}

char	*ft_strdup2(const char *src)
{
	int			i;
	char		*copy;
	int			len;

	len = 0;
	i = 0;
	if (!src)
		copy = (char*)src;
	while (src[i] != ' ' && src[i] != '\0')
		i++;
	len = i;
	if (!check_for_spaces(src, i))
		return (NULL);
	copy = (char *)malloc(sizeof(*src) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i] != ' ' && src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strdup(const char *src)
{
	int			i;
	char		*copy;
	int			len;

	len = 0;
	i = 0;
	if (!src)
		copy = (char*)src;
	while (src[i] != '\0')
	{
		i++;
		len++;
	}
	copy = (char *)malloc(sizeof(*src) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
