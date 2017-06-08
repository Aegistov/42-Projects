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
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= 	ft_printf_parse.c \
			ft_printf.c \
			ft_memalloc.c \
			ft_memcpy.c \
			ft_bzero.c \
			ft_printf_capture_flags.c \
			ft_printf_capture_width.c \
			ft_printf_capture_precision.c \
			ft_printf_capture_length.c \
			ft_printf_flag_dispatch.c \
			ft_pf_num_print_order.c \
			ft_pf_num_sign.c \
			ft_strlen.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_atoi.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_putchar_fd.c \
			ft_strfill.c \
			ft_strjoin.c \
			ft_strchr.c \
			ft_itoa.c \
			ft_itoa_hex.c \
			ft_pf_itoa_oct.c \
			ft_intlen.c \
			ft_intlen_hex.c \
			ft_pf_intlen_oct.c \
			ft_pf_llu_len_base.c \
			ft_strnew.c \
			ft_strdup.c \
			ft_pf_num_toa_dispatch.c \
			ft_pf_ud_toa.c \
			ft_pf_ud_len_base.c \
			ft_pf_d_toa.c \
			ft_pf_d_len_base.c \

OBJS	= $(SRCS:%.c=%.o)

.PHONY:	all comp NAME dir clean fclean re

all: comp $(NAME) dir

comp:
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME):
	ar rc $(NAME) $(OBJS)

dir:
	ranlib libftprintf.a

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
