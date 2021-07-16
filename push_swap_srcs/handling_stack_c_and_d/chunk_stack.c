/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 19:16:47 by sachouam          #+#    #+#             */
/*   Updated: 2021/07/16 19:57:51 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void
	ft_chunk_stack(t_stack **stack)
{
	double	i;
	double	chunk;
	int		size;

	i = 0;
	size = ft_stack_size(*stack);
	if (size >= 100 && size < 500)
		chunk = size / 5;
	else if (size >= 500)
		chunk = size / 11;
	printf("size = %lf\n", size);
	printf("chunk = %lf\n", chunk);
	while (i < size)
	{
		i += chunk;
		printf("i = %d\n", i);
	}
}
