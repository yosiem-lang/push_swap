/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshie <oshie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 23:30:43 by oshie             #+#    #+#             */
/*   Updated: 2025/08/07 23:34:09 by oshie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	char	name;
	int		size;
}	t_stack;

long long	ft_atoll(const char *str);
void		error_exit(void);
t_node		*new_node(int value);
void		init_stack(t_stack *stack, char name);
int			is_sorted(t_stack *a);
void		coordinate_compression(t_stack *a);
void		sort_all(t_stack *a, t_stack *b);
void		free_stack(t_stack *stack);
void		parse_args(t_stack *a, int argc, char **argv);

t_node		*pop_top(t_stack *stack);
void		push_top(t_stack *stack, t_node *node);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

void		sort_small(t_stack *a, t_stack *b);
void		sort_large(t_stack *a, t_stack *b);
void		handle_three_cases(t_stack *a, int top, int mid, int bot);
void		handle_three_other_cases(t_stack *a, int top, int mid, int bot);
void		sort_three(t_stack *a);

void		get_ranks(int original_tab[], int n, int compressed_tab[]);
void		populate_stack_with_ranks(t_stack *a, int temp_compressed_array[]);
void		push_min_to_b(t_stack *a, t_stack *b);
void		push_max_from_b(t_stack *a, t_stack *b);
void		push_chunks_to_b(t_stack *a, t_stack *b, int chunk_size);
int			find_min_pos(t_stack *a);
void		rotate_min_to_top(t_stack *a, int min_pos);
int			find_max_pos(t_stack *b);
void		rotate_max_to_top(t_stack *b, int max_pos);

#endif
