/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_stacks_02.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 20:01:56 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/09 18:46:37 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void
	ft_delete_elem(t_stack *elem)
{
	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;
	free(elem);
}

void
	ft_delete_first_elem(t_stack **root)
{
	if ((*root)->next != *root)
		ft_delete_elem((*root)->next);
}

void
	ft_delete_last_elem(t_stack **root)
{
	if ((*root)->prev != *root)
		ft_delete_elem((*root)->prev);
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
