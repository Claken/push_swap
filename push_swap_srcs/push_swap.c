/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:01:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/25 00:13:34 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int
	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || !ft_check_params(++av)
		|| !ft_create_stack_a(&stack_a, ac, av))
		return (0);
	printf("cool\n");
	ft_clear_stack(&stack_a);
	return (0);
}

	/*
	t_stack	*svg;
	i = -1;

	svg = stack_a;
	while (stack_a)
	{
		++i;
		printf("elem N°%d = %d\n", i + 1, stack_a->integer);
		if (stack_a->prev)
			printf("elem prev %d = %d\n", i, stack_a->prev->integer);
		stack_a = stack_a->next;
		printf("\n");
	}
	stack_a = svg;
	*/
