/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwart <cschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:38:20 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/15 14:06:41 by cschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*head = last;
}

void	rra(t_node **stack_a, t_flags *flags)
{
	if (*stack_a && (*stack_a)->next)
	{
		reverse_rotate(stack_a);
		flags->total++;
		flags->rra++;
		if (!flags->bench)
			ft_printf("rra\n");
	}
}

void	rrb(t_node **stack_b, t_flags *flags)
{
	if (*stack_b && (*stack_b)->next)
	{
		reverse_rotate(stack_b);
		flags->total++;
		flags->rrb++;
		if (!flags->bench)
			ft_printf("rrb\n");
	}
}

void	rrr(t_node **stack_a, t_node **stack_b, t_flags *flags)
{
	int	i ;

	i = 0;
	if (*stack_a && (*stack_a)->next)
	{
		reverse_rotate(stack_a);
		i = 1;
	}
	if (*stack_b && (*stack_b)->next)
	{
		reverse_rotate(stack_b);
		i = 1;
	}
	if (i)
	{
		flags->total++;
		flags->rrr++;
		if (!flags->bench)
			ft_printf("rrr\n");
	}
}

void	rev_rot_rrr(t_node **stack_a, t_node **stack_b, t_node *minst_node,
	t_flags *flags)
{
	while (*stack_b != minst_node->target_node && *stack_a != minst_node)
		rrr(stack_a, stack_b, flags);
	update_index(*stack_a);
	update_index(*stack_b);
}
