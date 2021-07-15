/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:25:35 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/14 18:19:45 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int
	ft_find_nb_to_put_on_top(t_stack **root, int mov)
{
	t_stack	*curr;
	int		i;

	curr = (*root)->next;
	i = -1;
	while (++i != mov)
		curr = curr->next;
	return (curr->integer);
}

void
	ft_rotate_and_push(t_stack **a, t_stack **b, int bi)
{
	int		mova;
	int		movb;
	int		half;
	int		topa;
	int		topb;

	mova = ft_check_nb_of_move_for_a(a, bi);
	movb = ft_check_nb_of_move_for_b(b, bi);
	half = ft_stack_size(*a) / 2;
	topa = ft_find_nb_to_put_on_top(a, mova);
	topb = ft_find_nb_to_put_on_top(b, movb);
	while ((*a)->next->integer != topa
		|| (*b)->next->integer != topb)
	{
		mova = ft_check_nb_of_move_for_a(a, bi);
		movb = ft_check_nb_of_move_for_b(b, bi);
		if (mova > half && movb > half)
			ft_reverse_rotate_both(a, b);
		else if (mova && movb && mova <= half && movb <= half)
			ft_rotate_both(a, b);
		else if (mova && mova <= half)
			ft_rotate_stack(a, 'a');
		else if (movb && movb <= half)
			ft_rotate_stack(b, 'b');
		else if (mova > half)
			ft_reverse_rotate_stack(a, 'a');
		else if (movb > half)
			ft_reverse_rotate_stack(b, 'b');
	}
	ft_push_stack_a(a, b, 'a');
}

	/*
	printf("half = %d\n", half);
	printf("topa = %d\n", topa);
	printf("topb = %d\n", topb);
	printf("a->next->int = %d\n", (*a)->next->integer);
	printf("b->next->int = %d\n", (*b)->next->integer);
	printf("mova = %d\n", mova);
	printf("movb = %d\n", movb);
	printf("bi %d\n", bi);
	*/

