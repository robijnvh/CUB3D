/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-hou <rvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:52:59 by rvan-hou          #+#    #+#             */
/*   Updated: 2020/03/11 11:29:22 by rvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char			*ft_strchr(const char *str, int c)
{
	char *ptr;

	ptr = (char *)str;
	while (*ptr != c)
	{
		if (!*ptr)
			return (0);
		ptr++;
	}
	return (ptr);
}

static int		ft_len(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		res;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	res = len1 + len2 + 1;
	return (res);
}

char			*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		i2;

	if (!s1 || !s2 || (!s1 && !s2))
		return (0);
	newstr = (char *)malloc(sizeof(char *) * (ft_len((char *)s1, (char *)s2)));
	if (!newstr)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	i2 = 0;
	while (s2[i2] != '\0')
	{
		newstr[i] = s2[i2];
		i++;
		i2++;
	}
	newstr[i] = '\0';
	return (newstr);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	if (!dst && !src)
		return (dst);
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
