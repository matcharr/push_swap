/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-11-15 10:00:00 by mathis            #+#    #+#             */
/*   Updated: 2023-11-15 10:00:00 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* Find max index in stack */
int	find_max_index(t_stack *stack)
{
	t_stack	*temp;
	int		max_index;
	int		max_pos;
	int		pos;

	if (!stack)
		return (0);
	temp = stack;
	max_index = temp->index;
	max_pos = 0;
	pos = 0;
	while (temp)
	{
		if (temp->index > max_index)
		{
			max_index = temp->index;
			max_pos = pos;
		}
		pos++;
		temp = temp->next;
	}
	return (max_pos);
}

/* Find max value in stack */
int	find_max_value(t_stack *stack)
{
	t_stack	*temp;
	int		max_index;

	if (!stack)
		return (0);
	temp = stack;
	max_index = temp->index;
	while (temp)
	{
		if (temp->index > max_index)
			max_index = temp->index;
		temp = temp->next;
	}
	return (max_index);
}

/* Push elements from stack_a to stack_b in chunks */
void	push_chunks(t_stack **stack_a, t_stack **stack_b, int chunk_size, int i)
{
	int	j;

	j = 0;
	while (j < chunk_size && *stack_a)
	{
		if ((*stack_a)->index <= i * chunk_size)
		{
			pb(stack_a, stack_b, 1);
			if ((*stack_b)->index <= (i * chunk_size) - (chunk_size / 2))
				rb(stack_b, 1);
			j++;
		}
		else
			ra(stack_a, 1);
	}
}

/* Move max element to top of stack_b and push to stack_a */
void	push_max_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max_pos;

	max_pos = find_max_index(*stack_b);
	if (max_pos <= get_stack_size(*stack_b) / 2)
		while ((*stack_b)->index != find_max_value(*stack_b))
			rb(stack_b, 1);
	else
		while ((*stack_b)->index != find_max_value(*stack_b))
			rrb(stack_b, 1);
	pa(stack_a, stack_b, 1);
}
