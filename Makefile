NAME		= push_swap

LIBFT		= libft

NAME_LIBFT	= libft/libft.a

CCL			= clang

CCM			= gcc

SRC			= push_swap_srcs/push_swap.c \
			push_swap_srcs/check_data/check_params.c \
			push_swap_srcs/check_data/functions_for_checking.c \
			push_swap_srcs/check_data/error_so_exit.c \
			push_swap_srcs/linked_list/functions_for_deleting_element.c \
			push_swap_srcs/linked_list/functions_for_moving_element.c \
			push_swap_srcs/linked_list/functions_for_stacks_01.c \
			push_swap_srcs/get_data/create_stack_a.c \
			push_swap_srcs/operations/the_operations_01.c \
			push_swap_srcs/operations/the_operations_02.c \
			push_swap_srcs/algorithm/functions_for_algorithm.c \
			push_swap_srcs/algorithm/functions_for_mediane.c \
			push_swap_srcs/algorithm/push_int_back_in_a.c \
			push_swap_srcs/algorithm/push_int_below_mediane.c \
			push_swap_srcs/algorithm/sort_three_integers.c \
			push_swap_srcs/algorithm/push_the_rest_in_b.c \
			push_swap_srcs/algorithm_2/check_best_move.c \
			push_swap_srcs/algorithm_2/rotate_and_push.c \
			print_stack.c \

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
