/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:01:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/03 19:02:04 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void
	ft_print_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*svg;
	t_stack	*curr;
	t_stack	*elem;
	int		med;
	int		even;
	int		half;
	int		i;

	med = ft_find_mediane(stack_a);
	even = ft_is_number_of_int_even(stack_a);
	half = ft_stack_size(*stack_a) / 2;
	printf("med = %d\n", med);
	printf("even = %d\n", even);
	printf("half = %d\n", half);
	//ft_push_stack_b(stack_a, stack_b, 'b');
	//ft_push_stack_b(stack_a, stack_b, 'b');
	//ft_push_stack_b(stack_a, stack_b, 'b');
	//ft_reverse_rotate_both(stack_a, stack_b);
	//ft_push_stack_a(stack_a, stack_b, 'a');
	//ft_push_stack_a(stack_a, stack_b, 'a');
	//ft_push_stack_a(stack_a, stack_b, 'a');
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
