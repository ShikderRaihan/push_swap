/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 21:13:04 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/17 18:25:40 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	err_dup(t_node *stack_a, int value)
{
	while (stack_a)
	{
		if (stack_a->nb == value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

// int err_rep(char **av, int value)
// {
// 	while(*av)
// 	{
// 		if (*av == value)
// 			return (1);
// 		(*av)++;
// 	}
// 	return (0);
// }

int	err_over_flow(char *av)
{
	long	val;

	val = ft_atol(av);
	if (val > INT_MAX || val < INT_MIN)
		return (0);
	return (1);
}

int	err_inval_char(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '+' || av[i] == '-')
		i++;
	if (av[i] == '\0')
		return (0);
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	show_err(int x, char **av, t_node *stack_a, bool test)
{
	if (x == 0)
	{
		write(2, "Error\n", 6);
		if (test)
			free_char(av);
		free_stack(&stack_a, NULL);
		exit (1);
	}
}
