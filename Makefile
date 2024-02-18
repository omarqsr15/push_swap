# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 16:49:24 by oel-qasr          #+#    #+#              #
#    Updated: 2024/02/18 19:39:37 by oel-qasr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =  ft_moves_push.c ft_moves_rr.c ft_moves_rrr.c ft_moves_ss.c \
		ft_push.c ft_split.c ft_sort_3_5.c ft_sort_100.c ft_sort_500.c \
		My_tools_0.c My_tools_1.c My_tools_2.c parsing.c push_swap.c ft_free.c\

SRCS_B =\

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

%.o : %.c push_swap.h bonus/checker.h
		$(cc) $(CFLAGS) -c $< -o %@

bonus: $(OBJS_B)
		$(CC) $(OBJS_B) -o checker

clean:
		$(RM) $(OBJS) $(OBJS_B)

fclean: clean
		$(RM) $(NAME) checker

re: fclean all

.PHONY: clean fclean
