/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:48:07 by oshie             #+#    #+#             */
/*   Updated: 2025/08/07 22:48:32 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

t_node	*new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		error_exit();
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	init_stack(t_stack *stack, char name)
{
	stack->top = NULL;
	stack->name = name;
	stack->size = 0;
}

int	is_sorted(t_stack *a)
{
	t_node	*temp;
	int		i;

	if (a->size <= 1)
		return (1);
	temp = a->top;
	i = 0;
	while (i < a->size - 1)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	init_stack(&a, 'a');
	init_stack(&b, 'b');
	parse_args(&a, argc, argv);
	if (is_sorted(&a))
	{
		free_stack(&a);
		free_stack(&b);
		return (0);
	}
	coordinate_compression(&a);
	sort_all(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
