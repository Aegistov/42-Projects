#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/25 00:18:13 by yolabi            #+#    #+#              #
#    Updated: 2017/04/25 02:42:40 by yolabi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_db
OUTFILE	=	-o ft_db
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCS	=	-I./includes/
SRCDIR	=	./srcs/
LIST	=	ft_db display_table get_table_name add_record del_record modify_record read_table vector t_list ft_memcpy save_table search_table help vector_two
SRCS	=	$(addsuffix .c,$(addprefix $(SRCDIR), $(LIST)))
OBJS	=	$(addsuffix .o,$(LIST))

.PHONY:	all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) $(INCS) $(OUTFILE)

clean:
	    /bin/rm -f $(OBJS)

fclean: clean
	    /bin/rm -f $(NAME)

re: fclean all
