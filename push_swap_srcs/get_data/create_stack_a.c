/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sachouam <sachouam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:41:05 by sachouam          #+#    #+#             */
/*   Updated: 2021/05/30 23:54:13 by sachouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int
	ft_create_stack_a(t_stack **stack, int ac, char **av)
{
	int		i;
	t_stack	*curr;

	i = -1;
	while (++i < ac - 1)
	{
		if (!ft_add_elem_back(stack, ft_atoi(av[i])))
			return (0);
	}
	curr = (*stack)->next;
	while (curr->next != *stack)
		curr = curr->next;
	(*stack)->prev = curr;
	printf("root = %p\n", *stack);
	printf("curr->int = %d\n", curr->integer);
	printf("stack->prev->int = %d\n", (*stack)->prev->integer);
	printf("stack->prev->next = %p\n", (*stack)->prev->next);
	return (1);
}
