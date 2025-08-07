/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:44:02 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/14 16:42:28 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	splitc(const char *str, char split)
{
	size_t	c;

	c = 0;
	while (*str)
	{
		while (*str && *str == split)
			str++;
		if (*str && *str != split)
		{
			c++;
			while (*str && *str != split)
				str++;
		}
	}
	return (c);
}

static char	*one_word(char const *s, char c)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

static int	free_all(char **result, int i)
{
	if (!result[i])
	{
		while (--i >= 0)
			free(result[i]);
		free(result);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	size_t		i;

	i = 0;
	split = (char **)malloc(sizeof(char *) * (splitc(s, c) + 1));
	if (!split)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			split[i] = one_word(s, c);
			while (*s && *s != c)
				s++;
			if (!free_all(split, i++))
				return (NULL);
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}
