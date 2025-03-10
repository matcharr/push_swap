/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-11-15 10:00:00 by mathis            #+#    #+#             */
/*   Updated: 2023-11-15 10:00:00 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Process instructions from standard input */
int	process_instructions(t_stack **stack_a, t_stack **stack_b)
{
	char	*instruction;

	instruction = get_next_line(0);
	if (!instruction)
		return (1);
	while (instruction)
	{
		if (!process_single_instruction(stack_a, stack_b, instruction))
		{
			free(instruction);
			return (0);
		}
		free(instruction);  // Free the instruction here
		instruction = get_next_line(0);
	}
	return (1);
}

/* Check if the stack is sorted and print result */
void	check_and_print_result(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

/* Main function for checker */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!init_stack(&stack_a, argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	/* Use regular version for normal operation */
	if (!process_instructions(&stack_a, &stack_b))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		write(2, "Error\n", 6);
		return (1);
	}
	check_and_print_result(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
