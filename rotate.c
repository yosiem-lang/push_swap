/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:42:11 by oshie             #+#    #+#             */
/*   Updated: 2025/07/29 18:38:48 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	a->top = a->top->next;
}

void	rb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	b->top = b->top->next;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
