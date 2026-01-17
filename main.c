/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:57:06 by cschwart          #+#    #+#             */
/*   Updated: 2026/01/17 19:02:04 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_char(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
	av = NULL;
}

void	init_main_stack(int ac, char **av,
	t_node **stack_a, t_flags *flags)
{
	int		i;
	bool	test;

	test = false;
	i = 1;
	read_flags(&ac, &av, flags);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		i = 0;
		test = true;
	}
	while (av[i])
	{
		check_input(*stack_a, av[i], av, test); 
		insert_af(stack_a, ft_atol(av[i]));
		i++;
	}
	if (test)
		free_char(av);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_flags	flags;

	stack_a = NULL;
	stack_b = NULL;
	ft_bzero(&flags, sizeof(t_flags));
	flags.algo = -1;
	if (ac < 2)
		return (0);
	init_main_stack(ac, av, &stack_a, &flags);
	flags.disorder = compute_disorder(stack_a, &flags);
	sort(&stack_a, &stack_b, &flags);
	// if (flags.bench)
	// {
	// 	while (stack_a)
	// 	{
	// 		printf("%d ", stack_a->nb);
	// 		stack_a = stack_a->next;
	// 	}
	// }
	free_stack(&stack_a, &stack_b);
	ft_bzero(&flags, sizeof(t_flags));
	return (0);
}

