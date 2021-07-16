/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:01:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/17 00:55:47 by sachouam         ###   ########.fr       */
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
	if (stack_a == NULL || stack_b == NULL)
		return (0);
	if (stack_c == NULL || stack_d == NULL)
		return (0);
	if (!ft_create_stack(&stack_a, ac, av))
		return (0);
	if (!ft_create_stack(&stack_c, ac, av))
		return (0);
	//ft_sorting_stack_a(&stack_a, &stack_b);

	//ft_insert_sort_stack(&stack_a, &stack_b, 'a', 'b');
	ft_insert_sort_stack(&stack_c, &stack_d, 0, 0);

	//ft_print_stack(&stack_a, &stack_b);
	ft_print_stack(&stack_c, &stack_d);

	ft_chunk_stack(&stack_c);

	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	ft_clear_stack(&stack_c);
	ft_clear_stack(&stack_d);
	return (0);
}
