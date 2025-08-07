/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:44:16 by oshie             #+#    #+#             */
/*   Updated: 2025/07/29 18:39:07 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	a->top = a->top->prev;
}

void	rrb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	b->top = b->top->prev;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
