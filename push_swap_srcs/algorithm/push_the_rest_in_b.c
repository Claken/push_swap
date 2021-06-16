/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_the_rest_in_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:57:53 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/16 14:06:55 by sachouam         ###   ########.fr       */
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
	ft_push_the_rest_in_b(t_stack **a, t_stack **b, int max, int min)
{
	t_stack	*svg;
	int		size;

	while ((*a)->next->integer != max
		&& (*a)->next->integer != min && ft_stack_size(*a) > 3)
		ft_push_stack_b(a, b, 'b');
	svg = *a;
	size = ft_stack_size(*a);
	*a = (*a)->next;
	while (*a != svg && ft_stack_size(*a) > 3)
	{
		if ((*a)->integer != min && (*a)->integer != max)
		{
			*a = svg;
			ft_how_you_rotate((*a)->integer, (size / 2), a, 'a');
			ft_push_the_rest_in_b(a, b, max, min);
		}
		*a = (*a)->next;
	}
	*a = svg;
}
