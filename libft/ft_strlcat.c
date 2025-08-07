/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:33:21 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/14 15:59:30 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strnlen(const char *str, size_t size)
{
	size_t	c;

	c = 0;
	while (*str && c <= size)
	{
		str++;
		c++;
	}
	return (c);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	i = 0;
	dlen = strnlen(dest, size);
	slen = ft_strlen(src);
	if (size <= dlen)
		return (size + slen);
	while (i < size - dlen - 1 && src[i])
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}
