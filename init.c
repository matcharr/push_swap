/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-11-15 10:00:00 by mathis            #+#    #+#             */
/*   Updated: 2023-11-15 10:00:00 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Process a single argument and add it to the stack */
static int	process_argument(t_stack **stack, char *arg)
{
	long	num;
	t_stack	*new_node;

	if (!is_valid_number(arg))
		return (0);
	num = ft_atol(arg);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	new_node = create_new_node((int)num);
	if (!new_node)
		return (0);
	add_node_back(stack, new_node);
	return (1);
}

/* Initialize the stack with the given arguments */
int	init_stack(t_stack **stack, int argc, char **argv)
{
	int		i;
	char	**args;
	int		result;

	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		args = ft_split(argv[1]);
		if (!args)
			return (0);
		result = init_stack_from_array(stack, args);
		free_split(args);
		return (result);
	}
	i = 1;
	while (i < argc)
	{
		if (!process_argument(stack, argv[i]))
			return (0);
		i++;
	}
	if (has_duplicates(*stack))
		return (0);
	return (1);
}

/* Initialize the stack from an array of strings */
int	init_stack_from_array(t_stack **stack, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!process_argument(stack, args[i]))
			return (0);
		i++;
	}
	if (has_duplicates(*stack))
		return (0);
	return (1);
}
