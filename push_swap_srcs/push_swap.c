/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:01:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/16 14:23:15 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void
	ft_sorting_stack_a(t_stack **a, t_stack **b)
{
	int	med;
	int	third;
	int	min;
	int	max;

	med = ft_find_mediane(a);
	third = ft_find_third_greater(a);
	min = ft_find_min(a);
	max = ft_find_max(a);
	if (ft_stack_size(*a) > 3)
	{
		ft_push_b_or_rotate_a(a, b, med, min);
		ft_push_the_rest_in_b(a, b, max, min);
		//ft_push_b_or_rotate_a(a, b, third);
	}
	ft_sort_three_integers(a);
	//ft_push_stack_a(a, b, 'a');
	//if ((*b)->next != *b)
	//	ft_rotate_b_or_push_a(a, b);
}

int
	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2 || !ft_check_params(++av))
		return (0);
	stack_a = ft_create_list();
	stack_b = ft_create_list();
	if (stack_a == NULL || stack_b == NULL)
		return (0);
	if (!ft_create_stack_a(&stack_a, ac, av))
		return (0);
	ft_sorting_stack_a(&stack_a, &stack_b);

	ft_print_stack(&stack_a, &stack_b);

	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	return (0);
}
