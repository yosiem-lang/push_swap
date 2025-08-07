/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:53:50 by oshie             #+#    #+#             */
/*   Updated: 2025/08/07 23:15:34 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->index > a->top->next->index)
		{
			sa(a);
			write(1, "sa\n", 3);
		}
	}
	else if (a->size == 3)
		sort_three(a);
	else
	{
		while (a->size > 3)
			push_min_to_b(a, b);
		sort_three(a);
		while (b->size > 0)
		{
			pa(a, b);
			write(1, "pa\n", 3);
		}
	}
}

void	sort_large(t_stack *a, t_stack *b)
{
	int	chunk_size;

	if (a->size <= 100)
		chunk_size = 15;
	else
		chunk_size = 35;
	push_chunks_to_b(a, b, chunk_size);
	sort_three(a);
	while (b->size > 0)
		push_max_from_b(a, b);
}

void	push_max_from_b(t_stack *a, t_stack *b)
{
	int	max_pos;

	max_pos = find_max_pos(b);
	rotate_max_to_top(b, max_pos);
	pa(a, b);
	write(1, "pa\n", 3);
}

void	push_chunks_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int	pushed_count;

	pushed_count = 0;
	while (a->size > 3)
	{
		if (a->top->index < pushed_count + chunk_size)
		{
			pb(a, b);
			write(1, "pb\n", 3);
			if (b->top->index < pushed_count + chunk_size / 2)
			{
				rb(b);
				write(1, "rb\n", 3);
			}
			pushed_count++;
		}
		else
		{
			ra(a);
			write(1, "ra\n", 3);
		}
	}
}
