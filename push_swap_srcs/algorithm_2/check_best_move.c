/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_best_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:55:23 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/23 00:01:18 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int
	ft_check_nb_of_move_for_a(t_stack **a, int b)
{
	t_stack	*curr;
	int		i;

	curr = (*a)->next;
	i = 0;
	while (curr->next != *a)
	{
		i++;
		if (b > curr->integer && b < curr->next->integer)
			break;
		curr = curr->next;
	}
	return (i);
}

int
	ft_check_nb_of_move_for_b(t_stack **b, int bi)
{
	t_stack	*curr;
	int		i;
	int		half;

	curr = (*b)->next;
	i = 0;
	while (curr->next != *b)
	{
		if (curr->integer == bi)
			break;
		i++;
		curr = curr->next;
	}
	return (i);
}

int
	ft_check_best_move(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	int		min;
	int		mova;
	int		movb;
	int		int_b;

	curr = (*b)->next;
	min = 0;
	int_b = 0;
	while (curr != *b)
	{
		mova = ft_check_nb_of_move_for_a(a, curr->integer);
		movb = ft_check_nb_of_move_for_b(b, curr->integer);
		if (movb > (ft_stack_size(*b) / 2))
			movb = ft_stack_size(*b) - movb;
		if (curr->prev == *b || (mova + movb) < min)
		{
			min = mova + movb;
			int_b = curr->integer;
		}
		curr = curr->next;
	}
	return (int_b);
}
