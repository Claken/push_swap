/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:23:56 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/26 23:09:44 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int
	ft_check_if_one_param(char *av)
{
	char	**tab;
	int		i;

	tab = ft_split(av, " ");
	if (tab == NULL)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	if (!ft_check_if_num_params(tab) || i == 1
		|| !ft_check_int_min_and_max(tab)
		|| !ft_check_if_no_duplicate(tab)
		|| ft_check_if_ascending_order(tab))
	{
		ft_free_tab(tab);
		return (0);
	}
	ft_free_tab(tab);
	return (1);
}

int
	ft_check_params(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (i == 1)
	{
		if (!ft_check_if_one_param(av[0]))
			return (0);
	}
	else
	{
		if (!ft_check_if_num_params(av)
			|| !ft_check_int_min_and_max(av)
			|| !ft_check_if_no_duplicate(av)
			|| ft_check_if_ascending_order(av))
			return (0);
	}
	return (1);
}
