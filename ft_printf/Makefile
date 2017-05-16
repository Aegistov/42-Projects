# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmorel <mmorel@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 14:24:38 by mmorel            #+#    #+#              #
#    Updated: 2017/05/10 14:24:42 by mmorel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
OUTFILE	= -o libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCS	= -I./includes/
SRCDIR	= ./srcs/
LIST	= ft_printf_parse ft_printf_output ft_printf ft_putchar_fd ft_printf_capture_flags ft_printf_flag_dispatch ft_strlen ft_printf_capture_width ft_strcpy ft_atoi ft_printf_capture_precision ft_putnbr_fd ft_putstr_fd
SRCS	= $(addsuffix .c,$(addprefix $(SRCDIR), $(LIST)))
OBJS	= $(addsuffix .o,$(LIST))

.PHONY:	all clean fclean re

all: comp $(NAME) dir

comp:
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME):
	ar rc $(NAME) $(OBJS)

dir:
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
