/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:24:19 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/22 18:31:13 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define MAXINT 2147483647
# define MININT 2147483648

typedef struct s_lst
{
	struct s_lst	*prev;
	void			*data;
	struct s_lst	*next;
}					t_lst;

int		ft_check_params(char **av);
int		ft_check_if_num_params(char **tab);
int		ft_check_int_min_and_max(char **tab);
int		ft_check_if_no_duplicate(char **tab);
int		ft_check_if_ascending_order(char **tab);
int		ft_error_exit(char *sentence);

#endif
