# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 16:49:24 by oel-qasr          #+#    #+#              #
#    Updated: 2024/02/20 02:04:32 by oel-qasr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =  mandatory/ft_moves_push.c mandatory/ft_moves_rr.c mandatory/ft_moves_rrr.c mandatory/ft_moves_ss.c \
		mandatory/ft_push.c mandatory/ft_split.c mandatory/ft_sort_3_5.c mandatory/ft_sort_big.c \
		mandatory/My_tools_0.c mandatory/My_tools_1.c mandatory/My_tools_2.c mandatory/parsing.c mandatory/push_swap.c mandatory/ft_free.c\

SRCS_B =	bonus/checker_bonus.c bonus/ft_moves_push_bonus.c bonus/ft_moves_rr_bonus.c bonus/ft_moves_rrr_bonus.c \
			bonus/ft_moves_ss_bonus.c bonus/ft_push_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c \
			bonus/My_tools_0_bonus.c bonus/parsing_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

mandatory/%.o : mandatory/%.c mandatory/push_swap.h
		$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS_B)
		$(CC) $(OBJS_B) -o checker

bonus/%.o : bonus/%.c bonus/checker_bonus.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS) $(OBJS_B)

fclean: clean
		$(RM) $(NAME) checker

re: fclean all

.PHONY: clean fclean
