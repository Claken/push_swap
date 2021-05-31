/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:41:05 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/31 18:11:35 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int
	ft_create_stack_a(t_stack **stack, int ac, char **av)
{
	int		i;

	i = -1;
	while (++i < ac - 1)
	{
		if (!ft_add_elem_back(stack, ft_atoi(av[i])))
			return (0);
	}
	ft_put_last_in_root_prev(stack);
	return (1);
}
