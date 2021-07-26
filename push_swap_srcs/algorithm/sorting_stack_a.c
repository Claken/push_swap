/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 11:19:59 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/22 15:56:49 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void
	ft_mov_int_to_top(t_stack **a, int chunkmax)
{
	int		topa;
	int		half;
	int		i;
	t_stack	*curr;

	topa = ft_check_int_to_put_on_top_of_a(a, chunkmax);
	half = ft_stack_size(*a) / 2;
	i = 0;
	curr = (*a)->next;
	while (curr->integer != topa)
	{
		i++;
		curr = curr->next;
	}
	while ((*a)->next->integer != topa)
	{
		if (i <= half)
			ft_rotate_stack(a, 'a');
		else
			ft_reverse_rotate_stack(a, 'a');
	}
}

static int
	ft_check_if_chunk_is_out(t_stack **a, int min, int max)
{
	t_stack	*curr;

	curr = (*a)->next;
	while (curr != *a)
	{
		if (curr->integer >= min && curr->integer <= max)
		{
			return (0);
		}
		curr = curr->next;
	}
	return (1);
}

static void
	ft_algorithm_for_100_int_and_more(t_stack **a, t_stack **b,
		t_stack **c, t_stack **d)
{
	float	div;
	float	chunk;
	int		chunkmax;
	int		chunkmin;

	div = ft_find_chunk_stack(a);
	chunk = 0;
	ft_insert_sort_stack(c, d, 0, 0);
	while ((*a)->next != *a)
	{
		chunk += div;
		chunkmax = ft_find_chunk_int_max(c, chunk);
		chunkmin = ft_find_chunk_int_min(c, chunk, div);
		while (!ft_check_if_chunk_is_out(a, chunkmin, chunkmax))
		{
			ft_mov_int_to_top(a, chunkmax);
			ft_push_stack_b(a, b, 'b');
		}
	}
	ft_rotate_b_or_push_a(a, b);
}

void
	ft_sorting_stack_a(t_stack **a, t_stack **b,
		t_stack **c, t_stack **d)
{
	int	size;

	size = ft_stack_size(*a);
	if (size < 100)
	{
		ft_insert_sort_stack(a, b, 'a', 'b');
	}
	else
	{
		ft_algorithm_for_100_int_and_more(a, b, c, d);
	}
}
