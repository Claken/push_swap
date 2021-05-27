/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_stacks_01.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:40:08 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/27 20:03:15 by sachouam         ###   ########.fr       */
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
	ft_clear_stack(t_stack **stack)
{
	t_stack	*svg;

	svg = NULL;
	while (*stack)
	{
		printf("%d\n", (*stack)->integer);
		svg = (*stack)->next;
		free(*stack);
		*stack = svg;
	}
}
