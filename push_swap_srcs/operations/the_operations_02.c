/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_operations_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:38:12 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/25 12:48:54 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void
	ft_swap_both(t_stack *a, t_stack *b)
{
	ft_swap_stack(a, 0);
	ft_swap_stack(b, 0);
	ft_putstr_fd("ss\n", 1);
}

void
	ft_rotate_both(t_stack *a, t_stack *b)
{
	ft_rotate_stack(a, 0);
	ft_rotate_stack(b, 0);
	ft_putstr_fd("rr\n", 1);
}

void
	ft_reverse_rotate_both(t_stack *a, t_stack *b)
{
	ft_reverse_rotate_stack(a, 0);
	ft_reverse_rotate_stack(b, 0);
	ft_putstr_fd("rrr\n", 1);
}
