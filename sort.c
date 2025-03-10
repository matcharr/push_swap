/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-11-15 10:00:00 by mathis            #+#    #+#             */
/*   Updated: 2023-11-15 10:00:00 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sort a stack with 3 elements */
void	sort_three(t_stack **stack)
{
	int	top;
	int	middle;
	int	bottom;

	if (get_stack_size(*stack) != 3)
		return ;
	top = (*stack)->value;
	middle = (*stack)->next->value;
	bottom = (*stack)->next->next->value;
	if (top > middle && middle < bottom && top < bottom)
		sa(stack, 1);
	else if (top > middle && middle > bottom)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ra(stack, 1);
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(stack, 1);
}

/* Sort a stack with 4 or 5 elements */
void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;

	size = get_stack_size(*stack_a);
	pushed = 0;
	index_stack(stack_a);
	while (pushed < size - 3)
	{
		if ((*stack_a)->index <= pushed + 1)
		{
			pb(stack_a, stack_b, 1);
			pushed++;
		}
		else
			ra(stack_a, 1);
	}
	sort_three(stack_a);
	while (pushed--)
		pa(stack_a, stack_b, 1);
}

/* Sort medium-sized stacks (6-100 elements) using an optimized algorithm */
void	sort_medium(t_stack **stack_a, t_stack **stack_b)
{
	int		chunk_count;
	int		chunk_size;
	int		i;
	int		size;

	size = get_stack_size(*stack_a);
	index_stack(stack_a);
	if (size <= 100)
		chunk_count = 5;
	else
		chunk_count = 9;
	chunk_size = size / chunk_count;
	i = 1;
	while (i <= chunk_count)
	{
		push_chunks(stack_a, stack_b, chunk_size, i);
		i++;
	}
	while (*stack_a)
		pb(stack_a, stack_b, 1);
	while (*stack_b)
		push_max_to_a(stack_a, stack_b);
}
