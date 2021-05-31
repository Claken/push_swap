/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_stacks_02.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 20:01:56 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/31 18:29:17 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void
	ft_put_last_in_root_prev(t_stack **stack)
{
	t_stack *curr;

	curr = (*stack)->next;
	while (curr->next != *stack)
		curr = curr->next;
	(*stack)->prev = curr;
}

void
	ft_push_elem_front(t_stack **stack, t_stack *elem)
{
	if ((*stack)->next != *stack)
	{
		elem->next = (*stack)->next;
		elem->next->prev = elem;
	}
	(*stack)->next = elem;
	(*stack)->next->prev = *stack;
	if ((*stack)->next->next == NULL)
		(*stack)->next->next = *stack;
	if ((*stack)->prev == *stack
		|| (*stack)->prev == NULL)
	ft_put_last_in_root_prev(stack);
}

void
	ft_push_elem_back(t_stack **stack, t_stack *elem)
{
	t_stack	*svg;

	svg = *stack;
	if ((*stack)->next == *stack)
	{
		(*stack)->next = elem;
		(*stack)->next->next = *stack;
		(*stack)->next->prev = *stack;
	}
	else
	{
		while ((*stack)->next != svg)
			*stack = (*stack)->next;
		(*stack)->next = elem;
		(*stack)->next->prev = *stack;
		(*stack)->next->next = svg;
		*stack = svg;
	}
}

t_stack
	*ft_remove_element(t_stack *elem, t_stack **stack)
{
	t_stack *removed;
	t_stack *before;
	t_stack *after;

	removed = NULL;
	if (elem != *stack)
	{
		removed = elem;
		before = elem->prev;
		after = elem->next;
		before->next = elem->next;
		after->prev = elem->prev;
		removed->next = NULL;
		removed->prev = NULL;
	}
	return (removed);
}
