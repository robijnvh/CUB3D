/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:12:13 by rvan-hou       #+#    #+#                */
/*   Updated: 2020/01/19 13:10:23 by rvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>

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
