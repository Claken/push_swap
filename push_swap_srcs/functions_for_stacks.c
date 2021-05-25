/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_stacks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:40:08 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/25 23:06:25 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack
	*ft_new_elem_in_stack(int integer)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (elem == NULL)
		return (NULL);
	elem->integer = integer;
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}

int
	ft_add_elem_back(t_stack **stack, int integer)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!(*stack))
	{
		*stack = ft_new_elem_in_stack(integer);
		if (stack == NULL)
			return (0);
	}
	else
	{
		while ((*stack)->next != NULL)
			*stack = (*stack)->next;
		(*stack)->next = ft_new_elem_in_stack(integer);
		if ((*stack)->next == NULL)
			return (0);
		(*stack)->next->prev = *stack;
		*stack = tmp;
	}
	return (1);
}

void
	ft_push_elem_front(t_stack **stack, t_stack *elem)
{
	if (*stack)
	{
		elem->next = *stack;
	}
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
	t_stack *tmp;

	removed = elem;
	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;
	removed->next = NULL;
	removed->prev = NULL;
	return (removed);
}

void
	ft_clear_stack(t_stack **stack)
{
	t_stack	*svg;

	svg = NULL;
	while (*stack)
	{
		svg = (*stack)->next;
		free(*stack);
		*stack = svg;
	}
}
