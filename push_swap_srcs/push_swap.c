/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:01:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/01 21:38:01 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"



static void
	ft_print_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*svg;
	t_stack	*curr;
	t_stack	*elem;
	double	size;
	int		i;

	size = ft_stack_size(*stack_a) / 2;
	printf("size %f\n", size);
	ft_push_stack_b(stack_a, stack_b, 'b');
	ft_push_stack_b(stack_a, stack_b, 'b');
	ft_push_stack_b(stack_a, stack_b, 'b');
	ft_reverse_rotate_both(stack_a, stack_b);
	ft_push_stack_a(stack_a, stack_b, 'a');
	ft_push_stack_a(stack_a, stack_b, 'a');
	ft_push_stack_a(stack_a, stack_b, 'a');
	curr = (*stack_a)->next;
	i = -1;
	while (curr != *stack_a)
	{
		++i;
		printf("elem N°%d = %d\n", i + 1, curr->integer);
		if (curr->prev != *stack_a)
			printf("elem prev %d = %d\n", i, curr->prev->integer);
		curr = curr->next;
		printf("\n");
	}
	curr = (*stack_b)->next;
	i = -1;
	while (curr != *stack_b)
	{
		++i;
		printf("elem N°%d = %d\n", i + 1, curr->integer);
		if (curr->prev != *stack_b)
			printf("elem prev %d = %d\n", i, curr->prev->integer);
		curr = curr->next;
		printf("\n");
	}
}

int
	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_create_list();
	stack_b = ft_create_list();
	if (ac < 2 || !ft_check_params(++av)
		|| !ft_create_stack_a(&stack_a, ac, av))
		return (0);
	ft_print_stack(&stack_a, &stack_b);
	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	return (0);
}
