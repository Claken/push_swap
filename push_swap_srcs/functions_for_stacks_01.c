/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_stacks_01.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:40:08 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/09 18:46:30 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static int
	ft_add_elem_before(t_stack *elem, int integer)
{
	t_stack	*new;

	new = ft_new_elem_in_stack(integer);
	if (new)
	{
		new->integer = integer;
		new->prev = elem->prev;
		new->next = elem;
		elem->prev->next = new;
		elem->prev = new;
		return (1);
	}
	return (0);
}

static int
	ft_add_elem_after(t_stack *elem, int integer)
{
	t_stack	*new;

	new = ft_new_elem_in_stack(integer);
	if (new)
	{
		new->integer = integer;
		new->prev = elem;
		new->next = elem->next;
		elem->next->prev = new;
		elem->next = new;
		return (1);
	}
	return (0);
}

int
	ft_add_to_top(t_stack **root, int integer)
{
	if (!ft_add_elem_after(*root, integer))
		return (0);
	return (1);
}

int 
	ft_add_to_bottom(t_stack **root, int integer)
{
	if (!ft_add_elem_before(*root, integer))
		return (0);
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
		printf("here\n");
		svg = curr->next;
		free(curr);
		curr = svg;
	}
	printf("fin\n");
	free(*stack);
	*stack = NULL;
}
