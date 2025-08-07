/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:49:09 by oshie             #+#    #+#             */
/*   Updated: 2025/08/07 22:49:21 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*next_node;
	int		i;

	if (stack->size == 0 || !stack->top)
		return ;
	stack->top->prev->next = NULL;
	temp = stack->top;
	i = 0;
	while (temp && i < stack->size)
	{
		next_node = temp->next;
		free(temp);
		temp = next_node;
		i++;
	}
	stack->top = NULL;
	stack->size = 0;
}

static void	check_duplicates_in_args(char **argv, int i, long long val)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if (ft_atoll(argv[j]) == val)
			error_exit();
		j++;
	}
}

void	parse_args(t_stack *a, int argc, char **argv)
{
	long long	num_val;
	int			num_int;
	int			i;

	i = argc - 1;
	while (i >= 1)
	{
		num_val = ft_atoll(argv[i]);
		num_int = (int) num_val;
		check_duplicates_in_args(argv, i, num_val);
		push_top(a, new_node(num_int));
		i--;
	}
}
