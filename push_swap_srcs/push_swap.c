/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:01:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/05 19:53:48 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void
	ft_push_b_if_necessary(t_stack **a, t_stack **b)
{
	int	med;

	med = ft_find_mediane(a);
	printf("med = %d\n", med);
	while ((*a)->next->integer < med)
		ft_push_stack_b(a, b, 'b');
}

static void
	ft_push_a_if_necessary(t_stack **a, t_stack **b)
{
	while ((*b)->next != *b)
		ft_push_stack_a(a, b, 'a');
}

static int
	ft_find_max(t_stack **root)
{
	int		max;
	t_stack	*curr;

	curr = (*root)->next;
	max = curr->integer;
	while (curr != *root)
	{
		if (curr->integer > max)
			max = curr->integer;
		curr = curr->next;
	}
	return (max);
}

static int
	ft_find_min(t_stack **root)
{
	int		min;
	t_stack	*curr;

	curr = (*root)->next;
	min = curr->integer;
	while (curr != *root)
	{
		if (curr->integer < min)
			min = curr->integer;
		curr = curr->next;
	}
	return (min);
}

static int
	ft_find_max(t_stack **root)
{
	int		max;
	t_stack	*curr;

	curr = (*root)->next;
	max = curr->integer;
	while (curr != *root)
	{
		if (curr->integer > max)
			max = curr->integer;
		curr = curr->next;
	}
	return (max);
}

static int
	ft_find_max(t_stack **root)
{
	int		max;
	t_stack	*curr;

	curr = (*root)->next;
	max = curr->integer;
	while (curr != *root)
	{
		if (curr->integer > max)
			max = curr->integer;
		curr = curr->next;
	}
	return (max);
}

static void
	ft_how_you_rotate(int max, int half, t_stack **root, int c)
{
	int		i;
	t_stack	*curr;

	i = 0;
	curr = (*root)->next;
	while (curr->integer != max)
	{
		i++;
		curr = curr->next;
	}
	if (i <= half)
		ft_rotate_stack(root, c);
	else
		ft_reverse_rotate_stack(root, c);
}

static void
	ft_rotate_b_if_necessary(t_stack **a, t_stack **b)
{
	int	max;
	int	half;

	while ((*b)->next != *b)
	{
		max = ft_find_max(b);
		half = ft_stack_size(*b) / 2;
		while ((*b)->next->integer != max)
			ft_how_you_rotate(max, half, b, 'b');
		ft_push_stack_a(a, b, 'a');
	}
}

static void
	ft_rotate_a_if_necessary(t_stack **a, t_stack **b)
{

}

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
	//printf("even = %d\n", even);
	//printf("half = %d\n", half);
	ft_push_b_if_necessary(stack_a, stack_b);
	ft_rotate_b_if_necessary(stack_a, stack_b);
	//ft_reverse_rotate_both(stack_a, stack_b);
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
