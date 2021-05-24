/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:24:19 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/24 23:56:10 by sachouam         ###   ########.fr       */
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
void				ft_clear_stack(t_stack **stack);
int					ft_create_stack_a(t_stack **stack, int ac, char **av);

#endif
