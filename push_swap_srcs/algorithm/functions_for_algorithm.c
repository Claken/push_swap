/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_algorithm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:36:57 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/27 02:32:44 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int
	ft_find_max(t_stack **root)
{
	int		max;
	t_stack	*curr;

	curr = (*root)->next;
	max = curr->integer;
	while (curr != *root)
	{
		if (curr->integer > max)
			max = curr->integer;
		curr = curr->next;
	}
	return (max);
}

int
	ft_find_min(t_stack **root)
{
	int		min;
	t_stack	*curr;

	curr = (*root)->next;
	min = curr->integer;
	while (curr != *root)
	{
		if (curr->integer < min)
			min = curr->integer;
		curr = curr->next;
	}
	return (min);
}

void
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
