/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_stacks_01.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:40:08 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/12 00:18:45 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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

int
	ft_stack_size(t_stack *root)
{
	int		i;
	t_stack	*curr;

	i = 0;
	if (!(curr = root->next))
		return (0);
	while (curr != root)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}
