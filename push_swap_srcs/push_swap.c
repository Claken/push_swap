/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:01:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/02 19:55:30 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int
	ft_find_mediane(t_stack **root)
{
	t_stack	*cpy;
	t_stack	*curr;
	int		sup;
	int		inf;
	int		half;

	half = ft_stack_size(*root) / 2;
	curr = (*root)->next;
	while (curr != *root)
	{
		cpy = (*root)->next;
		sup = 0;
		inf = 0;
		while (cpy != *root)
		{
			if (cpy->integer >= curr->integer)
				sup++;
			if (cpy->integer <= curr->integer)
				inf++;
			cpy = cpy->next;
		}
		printf("sup %d\n", sup);
		printf("inf %d\n", inf);
		printf("half%d\n", half);
		//printf("int %d\n\n", curr->integer);
		if ((sup == half || sup == half + 1)
			&& (inf == half || inf == half + 1))
			printf("\nmed %d\n", curr->integer);
		curr = curr->next;
		printf("\n");
	}
	return (0);
}

static void
	ft_print_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*svg;
	t_stack	*curr;
	t_stack	*elem;
	int		med;
	int		i;

	med = ft_find_mediane(stack_a);
	//printf("med = %d\n", med);
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
