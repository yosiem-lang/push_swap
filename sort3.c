/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:07:00 by oshie             #+#    #+#             */
/*   Updated: 2025/08/08 00:07:23 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *a)
{
	t_node	*current;
	int		min_index;
	int		min_pos;
	int		i;

	min_index = INT_MAX;
	min_pos = 0;
	current = a->top;
	i = 0;
	while (i < a->size)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

void	rotate_min_to_top(t_stack *a, int min_pos)
{
	int			i;
	int			min_index;
	t_node		*current;

	current = a->top;
	i = 0;
	while (i++ < min_pos)
		current = current->next;
	min_index = current->index;
	if (min_pos <= a->size / 2)
	{
		while (a->top->index != min_index)
		{
			ra(a);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while (a->top->index != min_index)
		{
			rra(a);
			write(1, "rra\n", 4);
		}
	}
}

void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_pos;

	min_pos = find_min_pos(a);
	rotate_min_to_top(a, min_pos);
	pb(a, b);
	write(1, "pb\n", 3);
}

int	find_max_pos(t_stack *b)
{
	t_node	*current;
	int		max_index;
	int		max_pos;
	int		i;

	max_index = -1;
	max_pos = 0;
	current = b->top;
	i = 0;
	while (i < b->size)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = i;
		}
		current = current->next;
		i++;
	}
	return (max_pos);
}

void	rotate_max_to_top(t_stack *b, int max_pos)
{
	int			i;
	int			max_index;
	t_node		*current;

	current = b->top;
	i = 0;
	while (i++ < max_pos)
		current = current->next;
	max_index = current->index;
	if (max_pos <= b->size / 2)
	{
		while (b->top->index != max_index)
		{
			rb(b);
			write(1, "rb\n", 3);
		}
	}
	else
	{
		while (b->top->index != max_index)
		{
			rrb(b);
			write(1, "rrb\n", 4);
		}
	}
}
