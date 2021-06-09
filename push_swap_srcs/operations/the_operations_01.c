/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_operations_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:14:23 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/09 18:46:41 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void
	ft_swap_stack(t_stack **stack, char c)
{
	int	val;

	if ((*stack)->next != *stack
		&& (*stack)->next->next != *stack)
	{
		val = (*stack)->next->next->integer;
		ft_delete_elem((*stack)->next->next);
		ft_add_to_top(stack, val);
		if (c == 'a')
			ft_putstr_fd("sa\n", 1);
		else if (c == 'b')
			ft_putstr_fd("sb\n", 1);
	}
}

void
	ft_push_stack_a(t_stack **stack_a, t_stack **stack_b, char c)
{
	int	val;

	if ((*stack_b)->next != *stack_b)
	{
		val = (*stack_b)->next->integer;
		ft_delete_first_elem(stack_b);
		ft_add_to_top(stack_a, val);
		if (c == 'a')
			ft_putstr_fd("pa\n", 1);
	}
}

void
	ft_push_stack_b(t_stack **stack_a, t_stack **stack_b, char c)
{
	int	val;

	if ((*stack_a)->next != *stack_a)
	{
		val = (*stack_a)->next->integer;
		ft_delete_first_elem(stack_a);
		ft_add_to_top(stack_b, val);
		if (c == 'b')
			ft_putstr_fd("pb\n", 1);
	}
}

void
	ft_rotate_stack(t_stack **stack, char c)
{
	int	val;

	val = (*stack)->next->integer;
	ft_delete_first_elem(stack);
	ft_add_to_bottom(stack, val);
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void
	ft_reverse_rotate_stack(t_stack **stack, char c)
{
	int	val;

	val = (*stack)->prev->integer;
	ft_delete_last_elem(stack);
	ft_add_to_top(stack, val);
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}
