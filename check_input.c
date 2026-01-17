/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 23:52:10 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/17 18:25:25 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(t_node *stack_a, char *av, char **argv, bool test)
{
	int	val;

	show_err(err_inval_char(av), argv, stack_a, test);
	show_err(err_over_flow(av), argv, stack_a, test);
	val = ft_atol(av);
	show_err(err_dup(stack_a, val), argv, stack_a, test);
}

int	ft_sorted(t_node *stack_a)
{
	if (!stack_a)
		return (1);
	while (stack_a && stack_a->next)
	{
		if (stack_a->nb > stack_a->next->nb)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	len_stack(t_node *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}
