NAME	= pushswap.a
SRC		= push_swap.c functions.c ft_swapush1.c ft_swapush2.c ft_algo.c functions2.c
CC		= gcc -Wall -Wextra -Werror
OBJ		= $(SRC:%.c=%.o)

all:		$(NAME)
			$(CC) $^ -o pushswap

$(OBJ):		$(SRC)
			$(CC) -I. -c $^

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $@

clean:
			rm -rf $(OBJ) pushswap

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
