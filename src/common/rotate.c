/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-11-15 10:00:00 by mathis            #+#    #+#             */
/*   Updated: 2023-11-15 10:00:00 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* Shift up all elements of stack a by 1.
The first element becomes the last */
void	ra(t_stack **stack_a, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	if (print)
		write(1, "ra\n", 3);
}

/* Shift up all elements of stack b by 1.
The first element becomes the last */
void	rb(t_stack **stack_b, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = *stack_b;
	while (last->next)
		last = last->next;
	*stack_b = first->next;
	first->next = NULL;
	last->next = first;
	if (print)
		write(1, "rb\n", 3);
}

/* ra and rb at the same time */
void	rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print)
		write(1, "rr\n", 3);
}
