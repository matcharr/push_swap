# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathis <mathis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023-11-15 10:00:00 by mathis            #+#    #+#              #
#    Updated: 2023-11-15 10:00:00 by mathis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c operations.c rotate.c reverse_rotate.c stack_utils.c \
	init.c utils.c sort.c helper.c sort_utils.c index.c split.c validation.c
CHECKER_SRCS = checker.c operations.c rotate.c reverse_rotate.c stack_utils.c \
	init.c utils.c sort.c helper.c sort_utils.c index.c checker_utils.c \
	get_next_line.c checker_ops.c split.c validation.c checker_debug.c

OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

all: $(NAME) $(CHECKER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(CHECKER): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) -o $(CHECKER) $(CHECKER_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(CHECKER_OBJS)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re