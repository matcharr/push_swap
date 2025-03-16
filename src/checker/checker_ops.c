/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:12:09 by marvin            #+#    #+#             */
/*   Updated: 2025/03/16 22:12:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	execute_swap_push(t_stack **stack_a, t_stack **stack_b, char *instruction)
{
	if (!ft_strcmp(instruction, "sa"))
		sa(stack_a, 0);
	else if (!ft_strcmp(instruction, "sb"))
		sb(stack_b, 0);
	else if (!ft_strcmp(instruction, "ss"))
		ss(stack_a, stack_b, 0);
	else if (!ft_strcmp(instruction, "pa"))
		pa(stack_a, stack_b, 0);
	else if (!ft_strcmp(instruction, "pb"))
		pb(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

int	execute_rotate(t_stack **stack_a, t_stack **stack_b, char *instruction)
{
	if (!ft_strcmp(instruction, "ra"))
		ra(stack_a, 0);
	else if (!ft_strcmp(instruction, "rb"))
		rb(stack_b, 0);
	else if (!ft_strcmp(instruction, "rr"))
		rr(stack_a, stack_b, 0);
	else if (!ft_strcmp(instruction, "rra"))
		rra(stack_a, 0);
	else if (!ft_strcmp(instruction, "rrb"))
		rrb(stack_b, 0);
	else if (!ft_strcmp(instruction, "rrr"))
		rrr(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

int	process_single_instruction(t_stack **stack_a, t_stack **stack_b,
			char *instruction)
{
	int	len;
	int	result;

	len = ft_strlen(instruction);
	if (len > 0 && instruction[len - 1] == '\n')
		instruction[len - 1] = '\0';
	result = execute_swap_push(stack_a, stack_b, instruction);
	if (result == 0)
		result = execute_rotate(stack_a, stack_b, instruction);
	return (result);
}
