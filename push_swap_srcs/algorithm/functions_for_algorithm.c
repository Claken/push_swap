/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_algorithm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:36:57 by sachouam          #+#    #+#             */
/*   Updated: 2021/06/11 19:50:43 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int
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

int
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
