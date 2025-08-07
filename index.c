/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:40:58 by oshie             #+#    #+#             */
/*   Updated: 2025/08/07 22:44:25 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	check_overflow(long long res, int sign, char next_char)
{
	if (sign == 1)
	{
		if (res > INT_MAX / 10
			|| (res == INT_MAX / 10 && (next_char - '0') > 7))
			error_exit();
	}
	else
	{
		if (res * sign < INT_MIN / 10
			|| (res * sign == INT_MIN / 10 && (next_char - '0') > 8))
			error_exit();
	}
	return (res * 10 + (next_char - '0'));
}

long long	ft_atoll(const char *str)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		error_exit();
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = check_overflow(res, sign, str[i]);
		i++;
	}
	if (str[i] != '\0')
		error_exit();
	return (res * sign);
}

static void	populate_arrays(t_stack *a, int temp_original_array[])
{
	t_node	*current;
	int		i;

	current = a->top;
	i = 0;
	while (i < a->size)
	{
		temp_original_array[i] = current->value;
		current = current->next;
		i++;
	}
}

void	coordinate_compression(t_stack *a)
{
	int		*temp_original_array;
	int		*temp_compressed_array;

	temp_original_array = (int *)malloc(sizeof(int) * a->size);
	if (!temp_original_array)
		error_exit();
	temp_compressed_array = (int *)malloc(sizeof(int) * a->size);
	if (!temp_compressed_array)
	{
		free(temp_original_array);
		error_exit();
	}
	populate_arrays(a, temp_original_array);
	get_ranks(temp_original_array, a->size, temp_compressed_array);
	populate_stack_with_ranks(a, temp_compressed_array);
	free(temp_original_array);
	free(temp_compressed_array);
}
