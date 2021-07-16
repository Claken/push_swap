/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:23:41 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/16 22:13:53 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void
	ft_insert_sort_stack(t_stack **one, t_stack **two, char a, char b)
{
	int	med;
	int	min;
	int	max;

	med = ft_find_mediane(one);
	min = ft_find_min(one);
	max = ft_find_max(one);
	if (ft_stack_size(*one) > 3)
		ft_rotate_a_or_push_b(one, two, a, b);
	ft_sort_three_integers(one, a);
	while ((*two)->next != *two)
		ft_push_stack_a(one, two, a);
}
