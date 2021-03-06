/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:24:19 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/26 23:18:28 by sachouam         ###   ########.fr       */
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

int					ft_find_max(t_stack **root);
int					ft_find_min(t_stack **root);
void				ft_how_you_rotate(int val, int half, t_stack **root, int c);

int					ft_find_mediane(t_stack **root);

void				ft_insert_sort_stack(t_stack **one, t_stack **two,
						char a, char b);

void				ft_rotate_b_or_push_a(t_stack **a, t_stack **b);

void				ft_rotate_a_or_push_b(t_stack **sa, t_stack **sb,
						char a, char b);

void				ft_sort_three_integers(t_stack **stack, char a);

int					ft_check_params(char **av);

int					ft_error_exit(void);

int					ft_check_if_num_params(char **tab);
int					ft_check_int_min_and_max(char **tab);
int					ft_check_if_no_duplicate(char **tab);
int					ft_check_if_ascending_order(char **tab);

int					ft_create_stack(t_stack **stack, int ac, char **av);

float				ft_find_chunk_stack(t_stack **root);

int					ft_find_chunk_int_max(t_stack **root, float chunk);
int					ft_find_chunk_int_min(t_stack **root, float chunk,
						float div);
int					ft_hold_first(t_stack **root, int chunkmax);
int					ft_hold_second(t_stack **root, int chunkmax);

void				ft_delete_elem(t_stack *elem);
void				ft_delete_first_elem(t_stack **root);
void				ft_delete_last_elem(t_stack **root);

int					ft_add_to_top(t_stack **root, int integer);
int					ft_add_to_bottom(t_stack **root, int integer);

t_stack				*ft_create_list(void);
t_stack				*ft_new_elem_in_stack(int integer);
void				ft_clear_stack(t_stack **stack);
int					ft_stack_size(t_stack *root);

void				ft_swap_stack(t_stack **stack, char c);
void				ft_push_stack_a(t_stack **stack_a,
						t_stack **stack_b, char c);
void				ft_push_stack_b(t_stack **stack_a,
						t_stack **stack_b, char c);
void				ft_rotate_stack(t_stack **stack, char c);
void				ft_reverse_rotate_stack(t_stack **stack, char c);

void				ft_swap_both(t_stack **a, t_stack **b);
void				ft_rotate_both(t_stack **a, t_stack **b);
void				ft_reverse_rotate_both(t_stack **a, t_stack **b);

void				ft_print_stack(t_stack **stack_a, t_stack **stack_b);

int					ft_check_int_to_put_on_top_of_a(t_stack **a, int chunkmax);
void				ft_sorting_stack_a(t_stack **a, t_stack **b,
						t_stack **c, t_stack **d);

#endif
