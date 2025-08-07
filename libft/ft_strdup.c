/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:49:35 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/14 16:47:00 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s;
	size_t	len;

	len = ft_strlen(str);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, str, len + 1);
	return (s);
}
