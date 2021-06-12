/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:01:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/12 20:10:27 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void
	ft_sorting_stack_a(t_stack **a, t_stack **b)
{
	int	med;
	int	third;

	med = ft_find_mediane(a);
	third = ft_find_third_greater(a);
	if (ft_stack_size(*a) > 3)
	{
		ft_push_b_or_rotate_a(a, b, med);
		ft_push_b_or_rotate_a(a, b, third);
	}
	ft_sort_three_integers(a);
	if ((*b)->next != *b)
		ft_rotate_b_or_push_a(a, b);
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
	if (!ft_create_stack_a(&stack_a, ac, av))
		return (0);
	ft_sorting_stack_a(&stack_a, &stack_b);
	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	return (0);
}
