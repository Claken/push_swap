NAME		= push_swap

LIBFT		= libft

NAME_LIBFT	= libft/libft.a

CCL			= clang

CCM			= gcc

SRC			= push_swap_srcs/push_swap.c \
			push_swap_srcs/check_data/check_params.c \
			push_swap_srcs/check_data/functions_for_checking.c \
			push_swap_srcs/check_data/error_so_exit.c \

OBJ			= $(SRC:.c=.o)

DEP			= $(SRC:.c=.d)

all:		$(NAME)

%.o : %.c
			$(CCL) -I . -o $@ -c $<

$(NAME_LIBFT):
			make -C $(LIBFT)

$(NAME):	$(NAME_LIBFT) $(OBJ)
			$(CCL) $(OBJ) $(NAME_LIBFT) -o $(NAME)

clean:
			rm -rf $(OBJ)
			rm -rf $(DEP)
			make clean -C $(LIBFT)

fclean:		clean
			rm -rf $(NAME)
			make fclean -C $(LIBFT)

re:			fclean all

run:
		make && make clean && clear
-include $(DEP)

.PHONY: all clean fclean re
