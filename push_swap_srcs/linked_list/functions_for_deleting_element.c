/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_deleting_element.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:20:46 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/12 00:18:28 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
