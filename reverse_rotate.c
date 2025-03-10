/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-11-15 10:00:00 by mathis            #+#    #+#             */
/*   Updated: 2023-11-15 10:00:00 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Shift down all elements of stack a by 1 */
void	rra(t_stack **stack_a, int print)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = *stack_a;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (print)
		write(1, "rra\n", 4);
}

/* Shift down all elements of stack b by 1 */
void	rrb(t_stack **stack_b, int print)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = *stack_b;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (print)
		write(1, "rrb\n", 4);
}

/* rra and rrb at the same time */
void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print)
		write(1, "rrr\n", 4);
}
