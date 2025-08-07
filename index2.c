/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:41:38 by oshie             #+#    #+#             */
/*   Updated: 2025/08/07 22:41:52 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_ranks(int original_tab[], int n, int compressed_tab[])
{
	int	i;
	int	j;
	int	rank;

	i = 0;
	while (i < n)
	{
		rank = 0;
		j = 0;
		while (j < n)
		{
			if (original_tab[j] < original_tab[i])
				rank++;
			j++;
		}
		compressed_tab[i] = rank;
		i++;
	}
}

void	populate_stack_with_ranks(t_stack *a, int temp_compressed_array[])
{
	t_node	*current;
	int		i;

	current = a->top;
	i = 0;
	while (i < a->size)
	{
		current->index = temp_compressed_array[i];
		current = current->next;
		i++;
	}
}
