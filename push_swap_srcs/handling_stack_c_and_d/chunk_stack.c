/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:16:47 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/26 23:18:46 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

float
	ft_find_chunk_stack(t_stack **root)
{
	float	chunk;
	int		size;

	size = ft_stack_size(*root);
	if (size >= 100 && size < 500)
		chunk = (double)size / 6;
	else if (size >= 500)
		chunk = (double)size / 13;
	return (chunk);
}

int
	ft_find_chunk_int_max(t_stack **root, float chunk)
{
	int		i;
	t_stack	*curr;

	i = -1;
	curr = *root;
	while (++i < chunk)
		curr = curr->next;
	return (curr->integer);
}

int
	ft_find_chunk_int_min(t_stack **root, float chunk, float div)
{
	int		i;
	float	chunkmin;
	t_stack	*curr;

	i = -1;
	chunkmin = chunk - div;
	curr = *root;
	while (++i < chunkmin)
		curr = curr->next;
	return (curr->integer);
}

int
	ft_hold_first(t_stack **root, int chunkmax)
{
	t_stack	*curr;

	curr = (*root)->next;
	while (curr->integer > chunkmax)
		curr = curr->next;
	return (curr->integer);
}

int
	ft_hold_second(t_stack **root, int chunkmax)
{
	t_stack	*curr;

	curr = (*root)->prev;
	while (curr->integer > chunkmax)
		curr = curr->prev;
	return (curr->integer);
}
