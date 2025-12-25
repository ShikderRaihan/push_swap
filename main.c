#include "push_swap.h"

int main(int ac, char **av)
{
	s_node *stack_a;
	s_node *stack_b;
	int i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
	{
		ft_printf("Error: No numbers provided\n");
		return (1);
	}
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		i = 0;
	}
	while (av[i])
	{
		insert_af(&stack_a, ft_atoi(av[i]));
		i++;
	}
	// if ft_sorted(stack_a)
	// 	free(stack_a);
	sa(stack_a);
	ra(&stack_a);
	pb(&stack_b, &stack_a);
	while (stack_a != NULL)
	{
		ft_printf("%d\n", stack_a->nb);
		stack_a = stack_a->next;
	}
	while (stack_b != NULL)
	{
		ft_printf("\n%d\n", stack_b->nb);
		stack_b = stack_b->next;
	}
	return (0);
}
