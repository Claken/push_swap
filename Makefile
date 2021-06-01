U_NAME		:= $(shell uname -s)

NAME		:= push_swap

LIBFT		:= libft

NAME_LIBFT	:= libft/libft.a

CC			:= clang

SRC			= push_swap_srcs/push_swap.c \
			push_swap_srcs/check_data/check_params.c \
			push_swap_srcs/check_data/error_so_exit.c \
			push_swap_srcs/check_data/functions_for_checking.c \
			push_swap_srcs/functions_for_stacks_01.c \
			push_swap_srcs/functions_for_stacks_02.c \
			push_swap_srcs/get_data/create_stack_a.c \
			push_swap_srcs/operations/the_operations_01.c \
			push_swap_srcs/operations/the_operations_02.c \

OBJ			= $(SRC:.c=.o)

DEP			= $(SRC:.c=.d)

all:		$(NAME)

%.o : %.c
			$(CC) -I . -o $@ -c $<

$(NAME_LIBFT):
			make -C $(LIBFT)

$(NAME):	$(NAME_LIBFT) $(OBJ)
			$(CC) $(OBJ) $(NAME_LIBFT) -o $(NAME)

clean:
			rm -rf $(OBJ)
			rm -rf $(DEP)
			make clean -C $(LIBFT)

fclean:		clean
			rm -rf $(NAME)
			make fclean -C $(LIBFT)

re:			fclean all

run:
		make fclean && make && make clean && clear
-include $(DEP)

.PHONY: all clean fclean re
