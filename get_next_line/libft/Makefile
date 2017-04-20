# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmorel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/31 16:15:22 by mmorel            #+#    #+#              #
#    Updated: 2016/10/31 16:15:25 by mmorel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = 	ft_strrchr.c \
		ft_putstr.c  \
		ft_memcpy.c  \
		ft_strcmp.c  \
		ft_strlcat.c  \
		ft_memmove.c  \
		ft_strncpy.c  \
		ft_wdct.c  \
		ft_lstmap.c  \
		ft_strsplit.c  \
		ft_lstadd.c  \
		ft_striter.c  \
		ft_isdigit.c  \
		ft_strstr.c  \
		ft_putnbr.c  \
		ft_strdel.c  \
		ft_memccpy.c  \
		ft_bzero.c  \
		ft_memchr.c  \
		ft_isalnum.c  \
		ft_putstr_fd.c  \
		ft_lstiter.c  \
		ft_lstdelone.c  \
		ft_toupper.c  \
		ft_strcpy.c  \
		ft_lstnew.c  \
		ft_putnbr_fd.c  \
		ft_strdup.c  \
		ft_striteri.c  \
		ft_intlen.c  \
		ft_strrev.c  \
		ft_strmap.c  \
		ft_putendl_fd.c  \
		ft_memdel.c  \
		ft_putchar.c  \
		ft_isascii.c  \
		ft_strnstr.c  \
		ft_strlen.c  \
		ft_strnew.c  \
		ft_strsub.c  \
		ft_memalloc.c  \
		ft_putendl.c  \
		ft_strncmp.c  \
		ft_strncat.c  \
		ft_inof.c  \
		ft_itoa.c  \
		ft_memcmp.c  \
		ft_strequ.c  \
		ft_putchar_fd.c  \
		ft_strtrim.c  \
		ft_memset.c  \
		ft_memrcpy.c  \
		ft_isalpha.c  \
		ft_strcat.c  \
		ft_tolower.c  \
		ft_strnequ.c  \
		ft_strjoin.c  \
		ft_strclr.c  \
		ft_isprint.c  \
		ft_atoi.c  \
		ft_strmapi.c  \
		ft_lstdel.c  \
		ft_strchr.c  \

OBJS = $(SRCS:%.c=%.o)

.PHONY: all comp NAME dir clean fclean re

all: comp $(NAME) dir

comp:
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME): 
	ar rc $(NAME) $(OBJS)

dir:
	ranlib libft.a

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
