/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_stacks_02.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 20:01:56 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/28 00:44:33 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void
	ft_push_elem_front(t_stack **stack, t_stack *elem)
{
	if (*stack)
		elem->next = *stack;
	*stack = elem;
	(*stack)->next->prev = *stack;
}

void
	ft_push_elem_back(t_stack **stack, t_stack *elem)
{
	t_stack *tmp;

	tmp = *stack;
	if (!(*stack))
		*stack = elem;
	else
	{
		while ((*stack)->next != NULL)
			*stack = (*stack)->next;
		(*stack)->next = elem;
		(*stack)->next->prev = *stack;
		*stack = tmp;
	}
}

t_stack
	*ft_remove_element(t_stack *elem)
{
	t_stack *removed;

	removed = elem;
	if (elem->prev)
		elem->prev->next = elem->next;
	else
		elem->prev = NULL;
	if (elem->next)
		elem->next->prev = elem->prev;
	else
		elem->next = NULL;
	removed->next = NULL;
	removed->prev = NULL;
	return (removed);
}
