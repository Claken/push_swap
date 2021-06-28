/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_int_below_mediane.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:46:56 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/28 21:37:51 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void
	ft_how_you_rotate(int val, int half, t_stack **root, int c)
{
	int		i;
	t_stack	*curr;

	i = 0;
	curr = (*root)->next;
	while (curr->integer != val)
	{
		i++;
		curr = curr->next;
	}
	if (i < half)
		ft_rotate_stack(root, c);
	else
		ft_reverse_rotate_stack(root, c);
}

void
	ft_push_b_or_rotate_a(t_stack **a, t_stack **b, int med, int min)
{
	t_stack	*svg;
	int		size;
	int		val;

	while ((*a)->next->integer < med
		&& (*a)->next->integer != min)
		ft_push_stack_b(a, b, 'b');
	svg = *a;
	size = ft_stack_size(*a);
	*a = (*a)->next;
	while (*a != svg)
	{
		if ((*a)->integer < med && (*a)->integer != min)
		{
			val = (*a)->integer;
			*a = svg;
			ft_how_you_rotate(val, (size / 2), a, 'a');
			ft_push_b_or_rotate_a(a, b, med, min);
		}
		*a = (*a)->next;
	}
	*a = svg;
}
