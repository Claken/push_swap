/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int_to_put_on_top_of_a.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 11:14:06 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/22 11:16:16 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int
	ft_number_of_operations_for_holdone(t_stack **a, int holdone)
{
	t_stack	*curr;
	int		i;

	curr = (*a)->next;
	i = 0;
	while (curr->integer != holdone)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

static int
	ft_number_of_operations_for_holdtwo(t_stack **a, int holdtwo)
{
	t_stack	*curr;
	int		j;

	curr = (*a)->prev;
	j = 0;
	while (curr->integer != holdtwo)
	{
		j++;
		curr = curr->prev;
	}
	return (j);
}

int
	ft_check_int_to_put_on_top_of_a(t_stack **a, int chunkmax)
{
	int		holdone;
	int		holdtwo;
	int		i;
	int		j;

	holdone = ft_hold_first(a, chunkmax);
	holdtwo = ft_hold_second(a, chunkmax);
	i = ft_number_of_operations_for_holdone(a, holdone);
	j = ft_number_of_operations_for_holdtwo(a, holdtwo);
	if (i < j)
		return (holdone);
	return (holdtwo);
}
