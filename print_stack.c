#include "push_swap.h"

void
	ft_print_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*curr;
	int		i;

	curr = (*stack_a)->next;
	i = -1;
	while (curr != *stack_a)
	{
		++i;
		printf("elem N°%d = %d\n", i + 1, curr->integer);
		if (curr->prev != *stack_a)
			printf("elem prev %d = %d\n", i, curr->prev->integer);
		else
			printf("elem prev %d = %d\n", i, curr->prev->prev->integer);
		curr = curr->next;
		printf("\n");
	}
	printf("elem next racine = %d\n", curr->next->integer);
	printf("\n");
	printf("\n");
	curr = (*stack_b)->next;
	i = -1;
	while (curr != *stack_b)
	{
		++i;
		printf("elem N°%d = %d\n", i + 1, curr->integer);
		if (curr->prev != *stack_b)
			printf("elem prev %d = %d\n", i, curr->prev->integer);
		curr = curr->next;
		printf("\n");
	}
}

