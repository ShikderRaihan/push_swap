/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 23:52:10 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/29 17:59:55 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(s_node *stack_a, char *av)
{
	int val;

	show_err(err_inval_char(av));
	show_err(err_over_flow(av));

	val = ft_atol(av);
	show_err(err_dup(stack_a, val));
}
int ft_sorted(s_node *stack_a)
{
	if (stack_a == NULL || stack_a->next == NULL)
		return (1);
	while(stack_a)
	{
		if (stack_a->nb > stack_a->next->nb)
				return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int len_stack(s_node *stack_a)
{
	int i;

	i = 0;
	while(stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}