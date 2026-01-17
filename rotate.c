/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwart <cschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:37:02 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/15 14:06:39 by cschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	*head = first->next;
	(*head)->prev = NULL;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_node **stack_a, t_flags *flags)
{
	if (*stack_a && (*stack_a)->next)
	{
		rotate(stack_a);
		flags->total++;
		flags->ra++;
		if (!flags->bench)
			ft_printf("ra\n");
	}
}

void	rb(t_node **stack_b, t_flags *flags)
{
	if (*stack_b && (*stack_b)->next)
	{
		rotate(stack_b);
		flags->total++;
		flags->rb++;
		if (!flags->bench)
			ft_printf("rb\n");
	}
}

void	rr(t_node **stack_a, t_node **stack_b, t_flags *flags)
{
	int	i;

	i = 0;
	if (*stack_a && (*stack_a)->next)
	{
		rotate(stack_a);
		i = 1;
	}
	if (*stack_b && (*stack_b)->next)
	{
		rotate(stack_b);
		i = 1;
	}
	if (i)
	{
		flags->total++;
		flags->rr++;
		if (!flags->bench)
			ft_printf("rr\n");
	}
}

void	rotate_rr(t_node **stack_a, t_node **stack_b, t_node *minst_node,
	t_flags *flags)
{
	while (*stack_b != minst_node->target_node && *stack_a != minst_node)
		rr(stack_a, stack_b, flags);
	update_index(*stack_a);
	update_index(*stack_b);
}
