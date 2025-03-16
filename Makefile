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
CFLAGS = -Wall -Wextra -Werror -I include

# Common source files
COMMON_SRCS = src/common/operations.c src/common/rotate.c \
	src/common/reverse_rotate.c \
	src/common/stack_utils.c src/common/init.c \
	src/common/conversion_utils.c src/common/char_utils.c \
	src/common/string_utils.c src/common/io_utils.c \
	src/common/sort.c \
	src/common/helper.c src/common/sort_utils.c src/common/index.c \
	src/common/split.c src/common/validation.c

# Push_swap specific source files
PUSH_SWAP_SRCS = src/push_swap/push_swap.c $(COMMON_SRCS)

# Checker specific source files
CHECKER_SRCS = src/checker/checker.c src/checker/checker_utils.c \
	src/checker/get_next_line.c src/checker/checker_ops.c \
	src/checker/checker_debug.c $(COMMON_SRCS)

# Object files
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

all: $(NAME) $(CHECKER)

$(NAME): $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(CHECKER): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re