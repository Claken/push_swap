/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_so_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:26:55 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/22 18:27:40 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int
	ft_error_exit(char *sentence)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(sentence, 1);
	return (0);
}

