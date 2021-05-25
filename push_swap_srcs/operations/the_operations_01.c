/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_operations_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:14:23 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/25 12:37:52 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void
	ft_swap_stack(t_stack *stack, char c)
{
	if (c == 'a')
		fd_putstr_fd("sa\n", 1);
	else if (c == 'b')
		fd_putstr_fd("sb\n", 1);
}

void
	ft_push_stack(t_stack *stack1, t_stack *stack2, char c)
{
	if (c == 'a')
		fd_putstr_fd("pa\n", 1);
	else if (c == 'b')
		fd_putstr_fd("pb\n", 1);
}

void
	ft_rotate_stack(t_stack *stack, char c)
{
	if (c == 'a')
		fd_putstr_fd("ra\n", 1);
	else if (c == 'b')
		fd_putstr_fd("rb\n", 1);
}

void
	ft_reverse_rotate_stack(t_stack *stack, char c)
{
	if (c == 'a')
		fd_putstr_fd("rra\n", 1);
	else if (c == 'b')
		fd_putstr_fd("rrb\n", 1);
}
