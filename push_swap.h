/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:24:19 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/19 11:28:02 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define MAXINT 2147483647
# define MININT 2147483648

typedef struct s_stack
{
	struct s_stack	*prev;
	int				integer;
	struct s_stack	*next;
}					t_stack;

int					ft_check_params(char **av);
int					ft_check_if_num_params(char **tab);
int					ft_check_int_min_and_max(char **tab);
int					ft_check_if_no_duplicate(char **tab);
int					ft_check_if_ascending_order(char **tab);
int					ft_error_exit(char *sentence);

t_stack				*ft_new_elem_in_stack(int integer);
void				ft_clear_stack(t_stack **stack);
t_stack				*ft_create_list(void);
int					ft_stack_size(t_stack *root);

int					ft_create_stack(t_stack **stack, int ac, char **av);

void				ft_swap_stack(t_stack **stack, char c);
void				ft_push_stack_a(t_stack **stack_a,
						t_stack **stack_b, char c);
void				ft_push_stack_b(t_stack **stack_a,
						t_stack **stack_b, char c);
void				ft_rotate_stack(t_stack **stack, char c);
void				ft_reverse_rotate_stack(t_stack **stack, char c);

int					ft_find_mediane(t_stack **root);
int					ft_find_third_greater(t_stack **root);
int					ft_find_max(t_stack **root);
int					ft_find_min(t_stack **root);
//void				ft_how_you_rotate(int val, int half, t_stack **root, int c);

void				ft_rotate_b_or_push_a(t_stack **a, t_stack **b);

void				ft_rotate_a_or_push_b(t_stack **sa, t_stack **sb, char a, char b);

void				ft_push_the_rest_in_b(t_stack **a, t_stack **b, int max, int min);
void				ft_push_b_or_rotate_a(t_stack **a, t_stack **b, int med, int min);
void				ft_sort_three_integers(t_stack **stack, char a);

void				ft_swap_both(t_stack **a, t_stack **b);
void				ft_rotate_both(t_stack **a, t_stack **b);
void				ft_reverse_rotate_both(t_stack **a, t_stack **b);

int					ft_add_to_top(t_stack **root, int integer);
int					ft_add_to_bottom(t_stack **root, int integer);
void				ft_delete_elem(t_stack *elem);
void				ft_delete_first_elem(t_stack **root);
void				ft_delete_last_elem(t_stack **root);

void				ft_print_stack(t_stack **stack_a, t_stack **stack_b);

int					ft_check_nb_of_move_for_a(t_stack **a, int b);
int					ft_check_nb_of_move_for_b(t_stack **b, int bi);
int					ft_check_best_move(t_stack **a, t_stack **b);
void				ft_rotate_and_push(t_stack **a, t_stack **b, int bi);

void				ft_insert_sort_stack(t_stack **one, t_stack **two, char a, char b);

void				ft_chunk_stack(t_stack **stack);
float				ft_find_chunk_stack(t_stack **root);
int					ft_hold_first(t_stack **root, int chunkmax);
int					ft_hold_second(t_stack **root, int chunkmax);
int					ft_find_chunk_int_max(t_stack **root, float chunk);

#endif
