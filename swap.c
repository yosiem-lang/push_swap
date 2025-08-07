/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 23:38:44 by oshie             #+#    #+#             */
/*   Updated: 2025/08/06 16:46:14 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	first->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev->next = second;
	first->prev = second;
	a->top = second;
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b || b->size < 2)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	first->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev->next = second;
	first->prev = second;
	b->top = second;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
