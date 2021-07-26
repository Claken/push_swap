/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:01:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/22 15:55:55 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	ft_sorting_stack_a(&stack_a, &stack_b, &stack_c, &stack_d);

	//ft_print_stack(&stack_a, &stack_b);

	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	ft_clear_stack(&stack_c);
	ft_clear_stack(&stack_d);
	return (0);
}
