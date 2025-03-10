/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-11-15 10:00:00 by mathis            #+#    #+#             */
/*   Updated: 2023-11-15 10:00:00 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Find the minimum unindexed value in the stack */
int	find_min_unindexed(t_stack *stack)
{
	t_stack	*temp;
	int		min;

	min = INT_MAX;
	temp = stack;
	while (temp)
	{
		if (temp->value < min && temp->index == 0)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

/* Assign index to the element with the given value */
void	assign_index(t_stack *stack, int value, int index)
{
	while (stack)
	{
		if (stack->value == value && stack->index == 0)
		{
			stack->index = index;
			return ;
		}
		stack = stack->next;
	}
}

/* Assign indices to the stack elements for sorting */
void	index_stack(t_stack **stack)
{
	t_stack	*current;
	int		min;
	int		index;

	index = 0;
	current = *stack;
	while (current)
	{
		min = find_min_unindexed(*stack);
		assign_index(*stack, min, ++index);
		current = current->next;
	}
}
