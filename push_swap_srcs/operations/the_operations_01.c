/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_operations_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:14:23 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/31 17:53:16 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void
	ft_swap_stack(t_stack **stack, char c)
{
	t_stack	*elem;

	if ((*stack)->next != *stack
		&& (*stack)->next->next != *stack)
	{
		elem = ft_remove_element((*stack)->next->next, stack);
		ft_push_elem_front(stack, elem);
		if (c == 'a')
			ft_putstr_fd("sa\n", 1);
		else if (c == 'b')
			ft_putstr_fd("sb\n", 1);
	}
}

void
	ft_push_stack_a(t_stack **stack_a, t_stack **stack_b, char c)
{
	t_stack	*elem;

	if ((*stack_b)->next != *stack_b)
	{
		elem = ft_remove_element((*stack_b)->next, stack_b);
		ft_push_elem_front(stack_a, elem);
		if (c == 'a')
			ft_putstr_fd("pa\n", 1);
	}
}

void
	ft_push_stack_b(t_stack **stack_a, t_stack **stack_b, char c)
{
	t_stack	*elem;

	if ((*stack_a)->next != *stack_a)
	{
		elem = ft_remove_element((*stack_a)->next, stack_a);
		ft_push_elem_front(stack_b, elem);
		if (c == 'b')
			ft_putstr_fd("pb\n", 1);
	}
}

void
	ft_rotate_stack(t_stack **stack, char c)
{
	t_stack	*elem;

	elem = ft_remove_element((*stack)->next, stack);
	ft_push_elem_back(stack, elem);
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void
	ft_reverse_rotate_stack(t_stack **stack, char c)
{
	t_stack	*elem;

	elem = ft_remove_element((*stack)->prev, stack);
	ft_push_elem_front(stack, elem);
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}
