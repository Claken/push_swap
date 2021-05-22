/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_checking.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:11:11 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/22 18:14:45 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int
	ft_check_if_num_params(char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			if (!ft_isdigit((tab[i][j])))
				if (!(tab[i][j] == '-' && ft_isdigit(tab[i][j + 1]) && j == 0))
					return (ft_error_exit("non-numerical parameter.s\n"));
	}
	return (1);
}

int
	ft_check_int_min_and_max(char **tab)
{
	int			i;
	long int	nbr;

	i = -1;
	while (tab[++i])
	{
		nbr = ft_atoi(tab[i]);
		if (nbr > MAXINT || nbr < -MININT)
			return (ft_error_exit("integer out of boudaries\n"));
	}
	return (1);
}

int
	ft_check_if_no_duplicate(char **tab)
{
	char	**cpy;
	int		i;
	int		j;
	int		count;

	cpy = tab;
	i = -1;
	while (tab[++i])
	{
		count = 0;
		j = -1;
		while (cpy[++j])
		{
			if (ft_atoi(cpy[j]) == ft_atoi(tab[i]))
				count++;
		}
		if (count > 1)
			return (ft_error_exit("duplicate in the parameters\n"));
	}
	return (1);
}

int
	ft_check_if_ascending_order(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (tab[i + 1]
			&& ft_atoi(tab[i]) > ft_atoi(tab[i + 1]))
			return (0);
	}
	return (1);
}
