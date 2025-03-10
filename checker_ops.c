/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-11-15 10:00:00 by mathis            #+#    #+#             */
/*   Updated: 2023-11-15 10:00:00 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Execute swap and push operations */
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

/* Execute rotate operations */
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

/* Execute the operation based on the instruction */
int	execute_operation(t_stack **stack_a, t_stack **stack_b, char *instruction)
{
	if (execute_swap_push(stack_a, stack_b, instruction))
		return (1);
	if (execute_rotate(stack_a, stack_b, instruction))
		return (1);
	return (0);
}

int	process_single_instruction(t_stack **stack_a, t_stack **stack_b, char *instruction)
{
	int	len;
	int	result;

	len = ft_strlen(instruction);
	if (len > 0 && instruction[len - 1] == '\n')
		instruction[len - 1] = '\0';

	// Debug output
	write(1, "Processing instruction: ", 24);
	write(1, instruction, ft_strlen(instruction));
	write(1, "\n", 1);

	result = execute_swap_push(stack_a, stack_b, instruction);
	if (result == 0)
		result = execute_rotate(stack_a, stack_b, instruction);

	// Debug output
	if (result)
		write(1, "Instruction executed successfully\n", 33);
	else
		write(1, "Invalid instruction\n", 20);

	return (result);
}
