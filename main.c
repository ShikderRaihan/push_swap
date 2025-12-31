#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	int		i;
	int		x;
	long	res;

	res = 0;
	i = 0;
	x = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			x *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * x);
}
// void free_list(s_node **stack_a)
// {
// 	while (*stack_a)
// 	{
// 		free (*stack_a);
// 		*stack_a = (*stack_a)->next;
// 	}
// }

int main(int ac, char **av)
{
	s_node *stack_a;
	s_node *stack_b;
	s_flags flags;
	int i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	ft_bzero(&flags, sizeof(s_flags));
	flags.algo = -1;
	if (ac < 2)
		return (0);
	read_flags(&ac, &av, &flags);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		i = 0;
	}
	while (av[i])
	{
		check_input(stack_a, av[i]);
		insert_af(&stack_a, ft_atol(av[i]));
		i++;
	}
	flags.disorder = compute_disorder(stack_a, &flags);
	if (flags.bench)
		disorder_metric(flags.disorder);
	// if ft_sorted(stack_a)
	// 	free(stack_a);
	// sa(stack_a);
	// ra(&stack_a);
	// pb(&stack_b, &stack_a);
	int j = len_stack(stack_a);
	if (j <= 10)
		simple_sort(stack_a, &flags);
	else 
		complex_sort(&stack_a, &stack_b, &flags);
	// while (stack_a != NULL)
	// {
	// 	ft_printf("%d\n", stack_a->nb);
	// 	stack_a = stack_a->next;
	// }
	// while (stack_b != NULL)
	// {
	// 	ft_printf("\n%d\n", stack_b->nb);
	// 	stack_b = stack_b->next;
	// }
	free_stack(stack_a);
	free_stack(stack_b);
	stack_a = NULL;
	stack_b = NULL;
	return (0);
}

