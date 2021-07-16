/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_integers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:44:12 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/16 19:02:18 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int
	check_if_ascending_order(t_stack **root)
{
	int		size;
	int		i;
	t_stack	*curr;

	size = ft_stack_size(*root);
	i = -1;
	curr = (*root)->next;
	while (++i < size)
	{
		if (curr->next != *root
			&& curr->integer > curr->next->integer)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void
	ft_sort_three_integers(t_stack **stack, char a)
{
	int	top;
	int	middle;
	int	bottom;

	while (!check_if_ascending_order(stack))
	{
		top = (*stack)->next->integer;
		middle = (*stack)->next->next->integer;
		bottom = (*stack)->next->next->next->integer;
		if ((top > middle && middle < bottom && bottom > top)
			|| (top > middle && middle > bottom && bottom < top)
			|| (top < middle && middle > bottom && bottom > top))
			ft_swap_stack(stack, a);
		else if (top > middle && middle < bottom && bottom < top)
			ft_rotate_stack(stack, a);
		else if (top < middle && middle > bottom && bottom < top)
			ft_reverse_rotate_stack(stack, a);
	}
}
