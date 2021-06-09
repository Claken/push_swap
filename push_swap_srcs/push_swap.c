/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:01:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/09 19:49:24 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void
	ft_how_you_rotate_two(int val, int half, t_stack **root, int c)
{
	int		i;
	t_stack	*curr;

	i = 0;
	curr = (*root)->next;
	while (curr->integer >= val)
	{
		i++;
		curr = curr->next;
	}
	if (i < half)
		ft_rotate_stack(root, c);
	else
		ft_reverse_rotate_stack(root, c);
}

static void
	ft_push_b_if_necessary(t_stack **a, t_stack **b, int med)
{
	t_stack	*curr;
	int		size;
	int		i;

	while ((*a)->next->integer < med)
		ft_push_stack_b(a, b, 'b');
	curr = (*a)->next;
	size = ft_stack_size(*a);
	i = -1;
	while (++i < size)
	{
		if (curr->integer < med)
		{
			ft_how_you_rotate_two(med, (size / 2), a, 'a');
			ft_push_b_if_necessary(a, b, med);
		}
		curr = curr->next;
	}
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

static void
	ft_how_you_rotate_one(int val, int half, t_stack **root, int c)
{
	int		i;
	t_stack	*curr;

	i = 0;
	curr = (*root)->next;
	while (curr->integer != val)
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
			ft_how_you_rotate_one(max, half, b, 'b');
		ft_push_stack_a(a, b, 'a');
	}
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
	printf("med = %d\n", med);
	printf("even = %d\n", even);
	printf("half = %d\n", half);
	ft_how_you_rotate_two(med, half, stack_a, 'a');
	ft_push_b_if_necessary(stack_a, stack_b, med);
	ft_rotate_b_if_necessary(stack_a, stack_b);
	//ft_reverse_rotate_both(stack_a, stack_b);
	//ft_reverse_rotate_stack(stack_a, 'a');
	//ft_rotate_stack(stack_a, 'a');
	//ft_swap_stack(stack_a, 'a');
	//ft_push_stack_b(stack_a, stack_b, 'b');
	//ft_push_stack_a(stack_a, stack_b, 'a');
	curr = (*stack_a)->next;
	i = -1;
	while (curr != *stack_a)
	{
		++i;
		printf("elem N°%d = %d\n", i + 1, curr->integer);
		if (curr->prev != *stack_a)
			printf("elem prev %d = %d\n", i, curr->prev->integer);
		else
			printf("elem prev %d = %d\n", i, curr->prev->prev->integer);
		curr = curr->next;
		printf("\n");
	}
	printf("elem next racine = %d\n", curr->next->integer);
	printf("\n");
	printf("\n");
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
