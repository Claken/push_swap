/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_int_below_mediane.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:46:56 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/11 19:47:16 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.c"

static void
	ft_how_you_rotate(int med, int half, t_stack **root, int c)
{
	int		i;
	t_stack	*curr;

	i = 0;
	curr = (*root)->next;
	while (curr->integer >= med)
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
	ft_push_b_or_rotate(t_stack **a, t_stack **b, int med)
{
	t_stack	*svg;
	int		size;
	int		i;

	while ((*a)->next->integer < med)
		ft_push_stack_b(a, b, 'b');
	svg = *a;
	size = ft_stack_size(*a);
	i = -1;
	*a = (*a)->next;
	while (*a != svg)
	{
		if ((*a)->integer < med)
		{
			*a = svg;
			ft_how_you_rotate_two(med, (size / 2), a, 'a');
			ft_push_b_or_rotate(a, b, med);
		}
		*a = (*a)->next;
	}
	*a = svg;
}
