# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 14:02:59 by saibelab          #+#    #+#              #
#    Updated: 2025/05/27 15:29:49 by saibelab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -I.

SRCS		= ft_printf.c \
				ft_printf_utils.c \
				ft_printf_num.c \
				ft_printf_str.c \

OBJS		= $(SRCS:.c=.o)

AR = ar rcs
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re bonus
