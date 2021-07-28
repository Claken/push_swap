/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_mediane.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:43:05 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/27 02:33:14 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int
	ft_is_number_of_int_even(t_stack **root)
{
	t_stack	*curr;
	int		i;

	curr = (*root)->next;
	i = 0;
	while (curr != *root)
	{
		curr = curr->next;
		i++;
	}
	i = i % 2;
	if (i)
		return (0);
	return (1);
}

static int
	ft_mediane_or_not(t_stack **root, int half, t_stack *curr)
{
	int		sup;
	int		inf;
	t_stack	*cpy;
	int		even;

	cpy = (*root)->next;
	sup = 0;
	inf = 0;
	even = ft_is_number_of_int_even(root);
	while (cpy != *root)
	{
		if (cpy->integer > curr->integer)
			sup++;
		if (cpy->integer < curr->integer)
			inf++;
		cpy = cpy->next;
	}
	if (even == 0 && (sup == half && inf == half))
		return (1);
	else if (even == 1 && (sup <= half && inf == half))
		return (1);
	return (0);
}

int
	ft_find_mediane(t_stack **root)
{
	t_stack	*cpy;
	t_stack	*curr;
	int		half;

	half = ft_stack_size(*root) / 2;
	curr = (*root)->next;
	while (curr != *root)
	{
		if (ft_mediane_or_not(root, half, curr))
			return (curr->integer);
		curr = curr->next;
	}
	return (0);
}
