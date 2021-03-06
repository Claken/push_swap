/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_int_back_in_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:48:15 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/27 02:49:50 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void
	ft_rotate_b_or_push_a(t_stack **a, t_stack **b)
{
	int	max;
	int	half;

	while ((*b)->next != *b)
	{
		max = ft_find_max(b);
		half = ft_stack_size(*b) / 2;
		while ((*b)->next->integer != max)
			ft_how_you_rotate(max, half, b, 'b');
		ft_push_stack_a(a, b, 'a');
	}
}
