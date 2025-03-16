/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:36:03 by marvin            #+#    #+#             */
/*   Updated: 2025/03/10 15:36:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* Find the position of the element with the given index */
int	get_position(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

/* Calculate the number of bits needed to represent the largest number */
int	get_max_bits(int size)
{
	int	max_bits;
	int	num;

	max_bits = 0;
	num = size;
	while (num > 0)
	{
		num >>= 1;
		max_bits++;
	}
	return (max_bits);
}

/* Process one bit position in radix sort */
void	process_bit(t_stack **stack_a, t_stack **stack_b, int bit_pos, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (is_sorted(*stack_a) && !*stack_b)
			return ;
		if (((*stack_a)->index >> bit_pos) & 1)
			ra(stack_a, 1);
		else
			pb(stack_a, stack_b, 1);
		j++;
	}
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}

/* Sort a large stack using radix sort */
void	sort_large(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max_bits;
	int	i;

	size = get_stack_size(*stack_a);
	max_bits = get_max_bits(size);
	index_stack(stack_a);
	i = 0;
	while (i < max_bits && !is_sorted(*stack_a))
	{
		process_bit(stack_a, stack_b, i, size);
		i++;
	}
}

/* Main sorting function */
void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a, 1);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_small(stack_a, stack_b);
	else
		sort_medium(stack_a, stack_b);
}
