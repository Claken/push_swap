/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:01:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/25 22:53:09 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void
	ft_print_stack(t_stack *stack_a)
{
	t_stack	*svg;
	t_stack	*curr;
	t_stack	*elem;
	int		i;

	i = -1;
	curr = stack_a;

	while (++i < 3)
		curr = curr->next;
	printf("data curr %d\n", curr->integer);
	//ft_push_elem_back(&stack_a, curr);
	elem = ft_remove_element(curr);
	printf("data elem %d\n", elem->integer);
	ft_push_elem_front(&stack_a, elem);
	free(elem);
//	stack_a = svg;
	svg = stack_a;
	i = -1;
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
}

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
	ft_print_stack(stack_a);
	ft_clear_stack(&stack_a);
	return (0);
}
