/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_stacks_01.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:40:08 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/28 23:16:03 by sachouam         ###   ########.fr       */
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
	t_stack	*svg;

	svg = *stack;
	if ((*stack)->next == *stack)
	{
		(*stack)->next = ft_new_elem_in_stack(integer);
		if ((*stack)->next == NULL)
			return (0);
		(*stack)->next->next = *stack;
		(*stack)->next->prev = *stack;
	}
	else
	{
		while ((*stack)->next != svg)
			*stack = (*stack)->next;
		(*stack)->next = ft_new_elem_in_stack(integer);
		if ((*stack)->next == NULL)
			return (0);
		(*stack)->next->prev = *stack;
		(*stack)->next->next = svg;
		*stack = svg;
	}
	return (1);
}

void
	ft_clear_stack(t_stack **stack)
{
	t_stack	*svg;
	t_stack	*curr;

	svg = NULL;
	curr = (*stack)->next;
	while (curr != *stack)
	{
		svg = curr->next;
		free(curr);
		curr = svg;
	}
	free(*stack);
	*stack = NULL;
}

t_stack
	*ft_create_list(void)
{
	t_stack	*root;

	root = malloc(sizeof(t_stack));
	if (!root)
		return (NULL);
	root->prev = root;
	root->next = root;
	return (root);
}
