/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:34:50 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/25 20:35:46 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(s_node **stack_a, s_node **stack_b)
{
	s_node *tmp;
	
	if(*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	if ((*stack_b) != NULL)
		(*stack_b)->prev = NULL;
	tmp->next = *stack_a;
	if (*stack_a != NULL)
		(*stack_a)->prev = tmp;
	tmp->prev = NULL;
	(*stack_a)= tmp;
}

void pa(s_node **stack_a, s_node **stack_b)
{
	if (*stack_b)
	{
		push(stack_a, stack_b);
		ft_printf("pa\n");
	}
}
void pb(s_node **stack_b, s_node **stack_a)
{
	if (*stack_a)
	{
		push(stack_b, stack_a);
		ft_printf("pb\n");
	}
}
