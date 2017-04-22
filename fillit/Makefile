NAME = fillit

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

LIB = -L./libft -Ilibft -lft

SRCS = 	fillit_algorithm.c \
		fillit_checker.c \
		fillit_map.c \
		fillit_test_suite.c \
		fillit_util.c \
		ft_mode.c \
		ft_sqt.c \
		fillit_checks.c \

.PHONY: all NAME clean fclean re

all: $(NAME)

$(NAME):
	@make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIB)

clean:
	/bin/rm -f ./libft/*.o

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f ./libft/libft.a

re: fclean all
