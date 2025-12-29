/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:34:50 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/29 18:08:48 by rshikder         ###   ########.fr       */
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

void pa(s_node **stack_a, s_node **stack_b, s_flags *flags)
{
	if (*stack_b)
	{
		push(stack_a, stack_b);
		flags->total++;
		flags->pa++;
		if(!flags->bench)
			ft_printf("pa\n");
	}
}
void pb(s_node **stack_b, s_node **stack_a, s_flags *flags)
{
	if (*stack_a)
	{
		push(stack_b, stack_a);
		flags->total++;
		flags->pb++;
		if(!flags->bench)
			ft_printf("pb\n");
	}
}
