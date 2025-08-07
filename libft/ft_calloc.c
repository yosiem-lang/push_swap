/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:28:38 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/12 13:55:48 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*calloc;

	if (size != 0 && number > ((size_t)-1) / size)
		return (NULL);
	calloc = (void *)malloc(number * size);
	if (calloc)
		ft_memset(calloc, 0, number * size);
	return (calloc);
}
