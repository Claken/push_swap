/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_moving_element.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:21:46 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/11 19:22:44 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
