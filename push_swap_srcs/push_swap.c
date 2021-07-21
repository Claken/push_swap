/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:01:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/22 01:30:28 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int
	ft_check_if_sorted(t_stack *root)
{
	t_stack	*curr;

	curr = root->next;
	while (curr != root)
	{
		if (curr->next != root
			&& curr->integer > curr->next->integer)
			return (0);
		curr = curr->next;
	}
	return (1);
}

static void
	ft_final_rotations(t_stack **a)
{
	int		half;
	int		i;
	t_stack	*curr;

	half = ft_stack_size(*a) / 2;
	i = 1;
	curr = (*a)->next;
	while (curr->integer < curr->next->integer)
	{
		i++;
		curr = curr->next;
	}
	//printf("i = %d\n", i);
	//printf("half = %d\n", half);
	while (!ft_check_if_sorted(*a))
	{
		if (i > half)
			ft_reverse_rotate_stack(a, 'a');
		else
			ft_rotate_stack(a, 'a');
	}
}

static void
	ft_sorting_stack_a(t_stack **a, t_stack **b)
{
	int	med;
	int	min;
	int	max;

	med = ft_find_mediane(a);
	min = ft_find_min(a);
	max = ft_find_max(a);
	if (ft_stack_size(*a) > 3)
	{
		//printf("1\n");
		//printf("med = %d\n", med);
		//ft_push_b_or_rotate_a(a, b, med, min);
		ft_rotate_a_or_push_b(a, b, 'a', 'b');
		//printf("2\n");
		//ft_push_the_rest_in_b(a, b, max, min);
	}
	//printf("3\n");
	ft_sort_three_integers(a, 'a');
	while ((*b)->next != *b)
	{
		//printf("4\n");
		//printf("best move : %d\n", ft_check_best_move(a, b));
		//ft_rotate_and_push(a, b, ft_check_best_move(a, b));
		ft_push_stack_a(a, b, 'a');
	}
	//printf("5\n");
	if (!ft_check_if_sorted(*a))
		ft_final_rotations(a);
}

static int
	ft_check_int_to_put_on_top(t_stack **a, int chunkmax)
{
	int		holdone;
	int		holdtwo;
	int		i;
	int		j;
	t_stack	*curr;

	holdone = ft_hold_first(a, chunkmax);
	holdtwo = ft_hold_second(a, chunkmax);
	i = 0;
	j = 0;
	curr = (*a)->next;
	while (curr->integer != holdone)
	{
		i++;
		curr = curr->next;
	}
	curr = (*a)->prev;
	while (curr->integer != holdtwo)
	{
		j++;
		curr = curr->prev;
	}
	if (i < j)
		return (holdone);
	return (holdtwo);
}

static void
	ft_mov_int_to_top(t_stack **a, int chunkmax)
{
	int		topa;
	int		half;
	int		i;
	t_stack	*curr;

	topa = ft_check_int_to_put_on_top(a, chunkmax);
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
	//printf("min = %d\n", min);
	//printf("max = %d\n", max);
	while (curr != *a)
	{
		if (curr->integer >= min && curr->integer <= max)
		{
			//printf("curr->int = %d\n", curr->integer);
			return (0);
		}
		curr = curr->next;
	}
	//printf("1\n");
	return (1);
}

static void
	ft_sorting_stack_a_02(t_stack **a, t_stack **b,
		t_stack **c, t_stack **d)
{
	int		size;
	float	div;
	float	chunk;
	int		chunkmax;
	int		chunkmin;

	size = ft_stack_size(*a);
	chunk = 0;
	if (size < 100)
	{
		ft_insert_sort_stack(a, b, 'a', 'b');
	}
	else
	{
		div = ft_find_chunk_stack(a);
		ft_insert_sort_stack(c, d, 0, 0);
		while ((*a)->next != *a)
		{
			chunk += div;
			chunkmax = ft_find_chunk_int_max(c, chunk);
			chunkmin = ft_find_chunk_int_min(c, chunk, div);
			//printf("chunkmin = %d\n", chunkmin);
			//printf("chunkmax = %d\n", chunkmax);
			while (!ft_check_if_chunk_is_out(a, chunkmin, chunkmax))
			{
				ft_mov_int_to_top(a, chunkmax);
				ft_push_stack_b(a, b, 'b');
			}
			//printf("topa = %d\n", ft_check_int_to_put_on_top(a, chunkmax));
		}
		ft_rotate_b_or_push_a(a, b);
	}
}

int
	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_c;
	t_stack	*stack_d;

	if (ac < 2 || !ft_check_params(++av))
		return (0);
	stack_a = ft_create_list();
	stack_b = ft_create_list();
	stack_c = ft_create_list();
	stack_d = ft_create_list();
	if (stack_a == NULL || stack_b == NULL
		|| stack_c == NULL || stack_d == NULL)
		return (0);
	if (!ft_create_stack(&stack_a, ac, av)
		|| !ft_create_stack(&stack_c, ac, av))
		return (0);
	//ft_sorting_stack_a(&stack_a, &stack_b);
	ft_insert_sort_stack(&stack_c, &stack_d, 0, 0);
	ft_sorting_stack_a_02(&stack_a, &stack_b, &stack_c, &stack_d);

	//ft_print_stack(&stack_a, &stack_b);
	//ft_insert_sort_stack(&stack_a, &stack_b, 'a', 'b');
	//chunk = ft_find_chunk_stack(&stack_c);
	//ft_print_stack(&stack_a, &stack_b);
	/*
	ft_print_stack(&stack_c, &stack_d);
	printf("chunk = %f\n", chunk);
	printf("hold_first   = %d\n", ft_hold_first(&stack_a, chunk));
	printf("hold_second  = %d\n", ft_hold_second(&stack_a, chunk));
	*/
	//ft_chunk_stack(&stack_c);

	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	ft_clear_stack(&stack_c);
	ft_clear_stack(&stack_d);
	return (0);
}
