/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomatsud <yomatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:51:23 by yomatsud          #+#    #+#             */
/*   Updated: 2025/05/12 13:55:25 by yomatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	c;
	int	n;

	c = 1;
	n = 0;
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n'
		|| *nptr == '\r' || *nptr == '\t' || *nptr == '\v')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			c = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = 10 * n + (*nptr - '0');
		nptr++;
	}
	return (c * n);
}
