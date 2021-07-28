/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:41:05 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/27 02:46:21 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int
	ft_if_one_param(t_stack **stack, char *av)
{
	char	**tab;
	int		i;

	tab = ft_split(av, " ");
	if (tab == NULL)
		return (0);
	i = -1;
	while (tab[++i])
	{
		if (!ft_add_to_bottom(stack, ft_atoi(tab[i])))
		{
			ft_free_tab(tab);
			return (0);
		}
	}
	ft_free_tab(tab);
	return (1);
}

int
	ft_create_stack(t_stack **stack, int ac, char **av)
{
	int	i;

	i = -1;
	if (ac < 3)
		return (ft_if_one_param(stack, *av));
	while (++i < ac - 1)
	{
		if (!ft_add_to_bottom(stack, ft_atoi(av[i])))
			return (0);
	}
	return (1);
}
