/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_best_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:55:23 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/08 03:04:52 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int
	ft_check_nb_of_move_for_a(t_stack **a, int b)
{
	t_stack	*curr;
	int		i;

	curr = (*a)->next;
	i = -1;
	//printf("b = %d\n", b);
	while (curr != *a)
	{
		i++;
		//printf("i = %d\n", i);
		//printf("curr->int = %d\n", curr->integer);
		if (curr->prev == *a)
		{
			//printf("curr->prev %p\n", curr->prev);
			if (b > curr->prev->prev->integer
				&& b < curr->integer)
			{
				//printf("curr->prev->prev->integer %d\n", curr->prev->prev->integer);
				//printf("curr->integer %d\n", curr->integer);
				//printf("\n");
				break;
			}
			i++;
		}
		if (curr->next == *a)
		{
			//printf("curr->next %p\n", curr->next);
			if (b < curr->next->next->integer
				&& b > curr->integer)
			{
				//printf("curr->next->next->integer %d\n", curr->next->next->integer);
				//printf("curr->integer %d\n", curr->integer);
				//printf("\n");
				break;
			}
		}
		if (b > curr->integer && b < curr->next->integer)
		{
			//printf("curr->integer %d\n", curr->integer);
			//printf("curr->next->integer %d\n", curr->next->integer);
			//printf("\n");
			break;
		}
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
