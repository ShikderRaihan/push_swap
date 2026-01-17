/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwart <cschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:34:50 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/15 14:06:43 by cschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	if ((*stack_b) != NULL)
		(*stack_b)->prev = NULL;
	tmp->next = *stack_a;
	if (*stack_a != NULL)
		(*stack_a)->prev = tmp;
	tmp->prev = NULL;
	(*stack_a) = tmp;
}

void	pa(t_node **stack_a, t_node **stack_b, t_flags *flags)
{
	if (*stack_b)
	{
		push(stack_a, stack_b);
		flags->total++;
		flags->pa++;
		if (!flags->bench)
			ft_printf("pa\n");
	}
}

void	pb(t_node **stack_b, t_node **stack_a, t_flags *flags)
{
	if (*stack_a)
	{
		push(stack_b, stack_a);
		flags->total++;
		flags->pb++;
		if (!flags->bench)
			ft_printf("pb\n");
	}
}
