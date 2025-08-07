/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:06:49 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/12 14:17:43 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (dest < src)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	if (dest > src)
	{
		while (len > 0)
		{
			len--;
			((unsigned char *)dest)[len] = ((const unsigned char *)src)[len];
		}
	}
	return (dest);
}
