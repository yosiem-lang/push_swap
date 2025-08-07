/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:45:18 by oshie             #+#    #+#             */
/*   Updated: 2025/08/07 22:16:57 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_top(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	if (stack->size == 0)
	{
		stack->top = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = stack->top;
		node->prev = stack->top->prev;
		stack->top->prev->next = node;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

t_node  *pop_top(t_stack *stack)
{
	t_node  *node;

	if (stack->size == 0)
		return (NULL);
	node = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
	}
	else
	{
		stack->top->prev->next = stack->top->next;
		stack->top->next->prev = stack->top->prev;
		stack->top = stack->top->next;
	}
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = pop_top(b);
	if (node)
		push_top(a, node);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = pop_top(a);
	if (node)
		push_top(b, node);
}
