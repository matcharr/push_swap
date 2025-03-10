/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-11-15 10:00:00 by mathis            #+#    #+#             */
/*   Updated: 2023-11-15 10:00:00 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Print the stack for debugging */
void	print_stack(t_stack *stack, char *name)
{
	write(1, name, ft_strlen(name));
	write(1, ": ", 2);
	while (stack)
	{
		ft_putnbr_fd(stack->value, 1);
		write(1, " ", 1);
		stack = stack->next;
	}
	write(1, "\n", 1);
}

/* Process instructions with debug output */
int	process_instructions_debug(t_stack **stack_a, t_stack **stack_b)
{
	char	*instruction;

	print_stack(*stack_a, "Initial stack_a");
	print_stack(*stack_b, "Initial stack_b");
	instruction = get_next_line(0);
	if (!instruction)
		return (1);
	while (instruction)
	{
		write(1, "Executing: ", 11);
		write(1, instruction, ft_strlen(instruction));
		if (!process_single_instruction(stack_a, stack_b, instruction))
		{
			free(instruction);
			return (0);
		}
		free(instruction);  // Free the instruction here
		print_stack(*stack_a, "stack_a");
		print_stack(*stack_b, "stack_b");
		instruction = get_next_line(0);
	}
	return (1);
}
