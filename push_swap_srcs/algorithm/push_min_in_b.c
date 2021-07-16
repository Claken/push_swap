/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min_in_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:56:52 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/16 19:03:01 by sachouam         ###   ########.fr       */
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
	if (i <= half)
		ft_rotate_stack(root, c);
	else
		ft_reverse_rotate_stack(root, c);
}

void
	ft_rotate_a_or_push_b(t_stack **sa, t_stack **sb, char a, char b)
{
	int	min;
	int	half;

	while (ft_stack_size(*sa) > 3)
	{
		min = ft_find_min(sa);
		half = ft_stack_size(*sa) / 2;
		while ((*sa)->next->integer != min)
			ft_how_you_rotate(min, half, sa, a);
		ft_push_stack_b(sa, sb, b);
	}
}
