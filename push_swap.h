/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:24:19 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/02 16:17:42 by sachouam         ###   ########.fr       */
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
int					ft_add_elem_back(t_stack **stack, int integer);
void				ft_put_last_in_root_prev(t_stack **stack);
void				ft_push_elem_front(t_stack **stack, t_stack *elem);
void				ft_push_elem_back(t_stack **stack, t_stack *elem);
t_stack				*ft_remove_element(t_stack *elem, t_stack **stack);
void				ft_clear_stack(t_stack **stack);
t_stack				*ft_create_list(void);
int					ft_stack_size(t_stack *root);

int					ft_create_stack_a(t_stack **stack, int ac, char **av);

void				ft_swap_stack(t_stack **stack, char c);
void				ft_push_stack_a(t_stack **stack_a, t_stack **stack_b, char c);
void				ft_push_stack_b(t_stack **stack_a, t_stack **stack_b, char c);
void				ft_rotate_stack(t_stack **stack, char c);
void				ft_reverse_rotate_stack(t_stack **stack, char c);

void				ft_swap_both(t_stack **a, t_stack **b);
void				ft_rotate_both(t_stack **a, t_stack **b);
void				ft_reverse_rotate_both(t_stack **a, t_stack **b);

#endif
