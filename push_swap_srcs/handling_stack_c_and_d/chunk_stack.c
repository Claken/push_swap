/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:16:47 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/17 00:55:43 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static float
	ft_find_chunk_stack(t_stack **root)
{
	float	chunk;
	int		size;

	size = ft_stack_size(*root);
	if (size >= 100 && size < 500)
		chunk = (double)size / 5;
	else if (size >= 500)
		chunk = (double)size / 11;
	return (chunk);
}

static int
	ft_hold_first(t_stack **root, float chunk)
{
	t_stack	*curr;

	curr = (*root)->next;
	while (curr->integer > chunk)
		curr = curr->next;
	return (curr->integer);
}

static int
	ft_hold_second(t_stack **root, float chunk)
{
	t_stack	*curr;

	curr = (*root)->prev;
	while (curr->integer > chunk)
		curr = curr->prev;
	return (curr->integer);
}

void
	ft_chunk_stack(t_stack **stack)
{
	int		i;
	float	chunk;
	float	newchunk;
	int		size;
	t_stack	*curr;

	size = ft_stack_size(*stack);
	chunk = ft_find_chunk_stack(stack);
	printf("size = %d\n", size);
	printf("chunk = %lf\n", chunk);
	curr = *stack;
	newchunk = 0;
	i = 0;
	printf("first  %d\n", ft_hold_first(stack, chunk));
	printf("second %d\n", ft_hold_second(stack, chunk));
	while (i < size)
	{
		newchunk += chunk;
		printf("newchunk = %f\n", newchunk);
		while (i < newchunk)
		{
			i++;
			curr = curr->next;
		}
		printf("i = %d\n", i);
		printf("curr->int = %d\n", curr->integer);
	}
}
