/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:01:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/31 02:06:36 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void
	ft_print_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*svg;
	t_stack	*curr;
	t_stack	*elem;

	printf("stack->prev %d\n", (*stack_a)->prev->integer);
	int		i;
/*
	i = -1;
	curr = (*stack_a)->next;
	while (++i < 3)
		curr = curr->next;
	printf("data curr %d\n", curr->integer);
	elem = ft_remove_element(curr, stack_a);
	printf("data elem %d\n", elem->integer);
	ft_push_elem_front(stack_a, elem);
	i = -1;
	while (++i < 4)
		curr = curr->next;
	printf("data curr %d\n", curr->integer);
	elem = ft_remove_element(curr, stack_a);
	printf("data elem %d\n", elem->integer);
	ft_push_elem_back(stack_a, elem);
	svg = *stack_a;
	printf("stack integer before %d\n", (*stack_a)->next->integer);
*/
	//ft_swap_stack(stack_a, 'a');
	//ft_reverse_rotate_stack(stack_a, 'a');
	//ft_rotate_stack(stack_a, 'a');
	ft_push_stack_b(stack_a, stack_b, 'b');
	ft_push_stack_b(stack_a, stack_b, 'b');
	ft_push_stack_b(stack_a, stack_b, 'b');
	ft_rotate_both(stack_a, stack_b);

	printf("stack->prev %d\n", (*stack_b)->prev->integer);
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
	printf("cool\n");
	ft_print_stack(&stack_a, &stack_b);
	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	return (0);
}
