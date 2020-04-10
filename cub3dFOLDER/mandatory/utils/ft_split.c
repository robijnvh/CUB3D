/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 10:30:42 by rvan-hou       #+#    #+#                */
/*   Updated: 2020/04/02 11:18:37 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char			**free_machine(char **str, int i)
{
	while (str)
	{
		free((void *)&str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

static int			ft_count_words(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\n')
	{
		while (str[i] != '\n' && str[i] == c)
			i++;
		if (str[i] != '\n' && str[i] != c)
		{
			count++;
			while (str[i] != '\n' && str[i] != c)
				i++;
		}
	}
	return (count);
}

static int			ft_length_word(char *s, int i, char c)
{
	int	count;

	count = 0;
	while (s[i] != '\n' && s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\n')
	{
		i++;
		count++;
	}
	return (count);
}

static char			*ft_malloc_word(const char *s, char c)
{
	int		i;
	int		i2;
	char	*str;

	i = 0;
	str = (char *)malloc(ft_length_word((char *)s, i, c) + 1);
	if (!str)
		return (0);
	i2 = 0;
	while (s[i] != '\n' && s[i] != c)
	{
		str[i2] = s[i];
		i++;
		i2++;
	}
	str[i2] = '\0';
	return (str);
}

char				**ft_split(char const *s, char c)
{
	int		i;
	char	**res;

	if (!s)
		return (NULL);
	i = 0;
	res = (char**)malloc(sizeof(char *) * ((ft_count_words(s, c)) + 1));
	if (!res)
		return (NULL);
	while (*s != '\n')
	{
		while (*s != '\n' && *s == c)
			s++;
		if (*s != '\n' && *s != c)
		{
			res[i] = ft_malloc_word(s, c);
			if (res[i] == 0)
				return (free_machine(res, i));
			i++;
			while (*s != '\n' && *s != c)
				s++;
		}
	}
	res[i] = NULL;
	return (res);
}
