/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-11-15 10:00:00 by mathis            #+#    #+#             */
/*   Updated: 2023-11-15 10:00:00 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* Stack operations */
void	sa(t_stack **stack_a, int print);
void	sb(t_stack **stack_b, int print);
void	ss(t_stack **stack_a, t_stack **stack_b, int print);
void	pa(t_stack **stack_a, t_stack **stack_b, int print);
void	pb(t_stack **stack_a, t_stack **stack_b, int print);
void	ra(t_stack **stack_a, int print);
void	rb(t_stack **stack_b, int print);
void	rr(t_stack **stack_a, t_stack **stack_b, int print);
void	rra(t_stack **stack_a, int print);
void	rrb(t_stack **stack_b, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int print);

/* Stack utils */
t_stack	*create_new_node(int value);
void	add_node_back(t_stack **stack, t_stack *new_node);
void	add_node_front(t_stack **stack, t_stack *new_node);
int		get_stack_size(t_stack *stack);
void	free_stack(t_stack **stack);

/* Parsing and initialization */
int		init_stack(t_stack **stack, int argc, char **argv);
int		is_valid_number(char *str);
int		has_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
int		find_min_unindexed(t_stack *stack);
void	assign_index(t_stack *stack, int value, int index);

/* Sorting algorithms */
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
void	sort_small(t_stack **stack_a, t_stack **stack_b);
void	sort_large(t_stack **stack_a, t_stack **stack_b);
void	sort_medium(t_stack **stack_a, t_stack **stack_b);
void	index_stack(t_stack **stack);
int		get_position(t_stack *stack, int index);
int		get_max_bits(int size);
void	process_bit(t_stack **stack_a, t_stack **stack_b, int bit_pos,
			int size);

/* Utils */
long	ft_atol(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* Helper functions */
int		find_max_index(t_stack *stack);
void	push_chunks(t_stack **stack_a, t_stack **stack_b,
			int chunk_size, int i);
void	push_max_to_a(t_stack **stack_a, t_stack **stack_b);
int		find_max_value(t_stack *stack);

/* Checker utils */
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*get_next_line(int fd);
char	*init_line(void);
char	*process_buffer(char *line, char *buffer, int bytes_read);
int		execute_operation(t_stack **stack_a, t_stack **stack_b,
			char *instruction);
int		process_instructions(t_stack **stack_a, t_stack **stack_b);
int		execute_swap_push(t_stack **stack_a, t_stack **stack_b,
			char *instruction);
int		execute_rotate(t_stack **stack_a, t_stack **stack_b, char *instruction);
int		process_single_instruction(t_stack **stack_a, t_stack **stack_b,
			char *instruction);
void	check_and_print_result(t_stack *stack_a, t_stack *stack_b);

/* String utils */
char	**ft_split(char const *s);
void	free_split(char **split);
char	*ft_strchr(const char *s, int c);
int		init_stack_from_array(t_stack **stack, char **args);

/* Debug functions */
void	print_stack(t_stack *stack, char *name);
int		process_instructions_debug(t_stack **stack_a, t_stack **stack_b);

#endif
