/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:01:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/11 19:14:28 by sachouam         ###   ########.fr       */
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
	ft_push_b_or_rotate(t_stack **a, t_stack **b, int med)
{
	t_stack	*svg;
	int		size;
	int		i;

	while ((*a)->next->integer < med)
		ft_push_stack_b(a, b, 'b');
	svg = *a;
	size = ft_stack_size(*a);
	i = -1;
	*a = (*a)->next;
	while (*a != svg)
	{
		if ((*a)->integer < med)
		{
			*a = svg;
			ft_how_you_rotate_two(med, (size / 2), a, 'a');
			ft_push_b_or_rotate(a, b, med);
		}
		*a = (*a)->next;
	}
	*a = svg;
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
	ft_rotate_b_or_push_a(t_stack **a, t_stack **b)
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

static int
	check_if_ascending_order(t_stack **root)
{
	int		size;
	int		i;
	t_stack	*curr;

	size = ft_stack_size(*root);
	i = -1;
	curr = (*root)->next;
	while (++i < size)
	{
		if (curr->next != *root
			&& curr->integer > curr->next->integer)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void
	ft_sort_three_integers(t_stack **a)
{
	int		top;
	int		middle;
	int		bottom;

	while (!check_if_ascending_order(a))
	{
		top = (*a)->next->integer;
		middle = (*a)->next->next->integer;
		bottom = (*a)->next->next->next->integer;
		if ((top > middle && middle < bottom && bottom > top)
			|| (top > middle && middle > bottom && bottom < top)
			|| (top < middle && middle > bottom && bottom > top))
			ft_swap_stack(a, 'a');
		else if (top > middle && middle < bottom && bottom < top)
			ft_rotate_stack(a, 'a');
		else if (top < middle && middle > bottom && bottom < top)
			ft_reverse_rotate_stack(a, 'a');
	}
}
/*
void
	ft_sort_3_integers(t_stack **a)
{
	int		top;
	int		middle;
	int		bottom;

	top = (*a)->next->integer;
	middle = (*a)->next->next->integer;
	bottom = (*a)->next->next->next->integer;
	if (top > middle && middle < bottom && bottom > top)
		ft_swap_stack(a, 'a');
	else if (top > middle && middle > bottom && bottom < top)
	{
		ft_swap_stack(a, 'a');
		ft_reverse_rotate_stack(a, 'a');
	}
	else if (top > middle && middle < bottom && bottom < top)
		ft_rotate_stack(a, 'a');
	else if (top < middle && middle > bottom && bottom > top)
	{
		ft_swap_stack(a, 'a');
		ft_rotate_stack(a, 'a');
	}
	else if (top < middle && middle > bottom && bottom < top)
		ft_reverse_rotate_stack(a, 'a');
}
*/


static int
	ft_find_third_greater(t_stack **root)
{
	int		nbr;
	t_stack	*cpy;
	t_stack	*curr;

	cpy = (*root)->next;
	while (cpy != *root)
	{
		curr = (*root)->next;
		nbr = 0;
		while (curr != *root)
		{
			if (curr->integer > cpy->integer)
				nbr++;
			curr = curr->next;
		}
		if (nbr == 2)
			return (cpy->integer);
		cpy = cpy->next;
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
	int		even;
	int		half;
	int		i;
	int		third;

	med = ft_find_mediane(stack_a);
	even = ft_is_number_of_int_even(stack_a);
	half = ft_stack_size(*stack_a) / 2;
	third = ft_find_third_greater(stack_a);
	//printf("med = %d\n", med);
	//printf("even = %d\n", even);
	//printf("half = %d\n", half);
	//printf("third greater bf push = %d\n", third);
	//ft_how_you_rotate_two(med, half, stack_a, 'a');
	//printf("1\n");
	if (ft_stack_size(*stack_a) > 3)
	{
		ft_push_b_or_rotate(stack_a, stack_b, med);
	//printf("2\n");
		ft_push_b_or_rotate(stack_a, stack_b, third);
	}
	//printf("min = %d\nmax = %d\n", ft_find_min(stack_a), ft_find_max(stack_a));
	//printf("third greater = %d\n", ft_find_third_greater(stack_a));
	//printf("3\n");
	ft_sort_three_integers(stack_a);
	//printf("4\n");
	if ((*stack_b)->next != *stack_b)
		ft_rotate_b_or_push_a(stack_a, stack_b);
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
