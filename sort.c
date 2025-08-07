/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:52:32 by oshie             #+#    #+#             */
/*   Updated: 2025/08/07 23:23:19 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_three_cases(t_stack *a, int top, int mid, int bot)
{
	if (top > mid && mid < bot && top < bot)
	{
		sa(a);
		write(1, "sa\n", 3);
	}
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
		write(1, "sa\nrra\n", 7);
	}
	else if (top > mid && mid < bot && top > bot)
	{
		ra(a);
		write(1, "ra\n", 3);
	}
}

void	handle_three_other_cases(t_stack *a, int top, int mid, int bot)
{
	if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
		write(1, "sa\nra\n", 6);
	}
	else if (top < mid && mid > bot)
	{
		rra(a);
		write(1, "rra\n", 4);
	}
}

void	sort_three(t_stack *a)
{
	int	top_idx;
	int	mid_idx;
	int	bot_idx;

	if (a->size <= 1 || is_sorted(a))
		return ;
	top_idx = a->top->index;
	mid_idx = a->top->next->index;
	bot_idx = a->top->next->next->index;
	handle_three_cases(a, top_idx, mid_idx, bot_idx);
	handle_three_other_cases(a, top_idx, mid_idx, bot_idx);
}

void	sort_all(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size <= 6)
		sort_small(a, b);
	else
		sort_large(a, b);
}
