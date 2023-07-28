# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 17:01:59 by minjeon2          #+#    #+#              #
#    Updated: 2023/07/29 03:48:52 by minjeon2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g
NAME = push_swap
LIBFT = ./libft/libft.a
LIBFT_DIR = libft
SRCS = circular_doubly_linked_list_1.c circular_doubly_linked_list_2.c push_command.c rotate_command.c \
swap_command.c reverse_rotate_command.c main.c partitioning_stack.c finding_minimum_command_greedy.c idx_maker.c \
stack_rotater.c utils.c input_checker.c count_command.c error.c
OBJS = $(SRCS:.c=.o)

.PHONY : clean fclean re all bonus

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) fclean
	rm -f $(OBJS)

fclean:
	$(MAKE) clean
	rm -f $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c -o $@ $?
