/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwart <cschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:34:32 by cschwart          #+#    #+#             */
/*   Updated: 2026/01/15 14:05:03 by cschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **stack_a, t_node **stack_b, t_flags *flags)
{
	t_node	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	if (*stack_b != NULL)
		(*stack_b)->prev = NULL;
	tmp->next = *stack_a;
	if (*stack_a != NULL)
		(*stack_a)->prev = tmp;
	tmp->prev = NULL;
	*stack_a = tmp;
	flags->pa++;
	flags->total++;
	if (!flags->bench)
		ft_printf("pa\n");
}

void	push_b(t_node **stack_a, t_node **stack_b, t_flags *flags)
{
	t_node	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = tmp->next;
	if (*stack_a != NULL)
		(*stack_a)->prev = NULL;
	tmp->next = *stack_b;
	if (*stack_b != NULL)
		(*stack_b)->prev = tmp;
	tmp->prev = NULL;
	*stack_b = tmp;
	flags->pb++;
	flags->total++;
	if (!flags->bench)
		ft_printf("pb\n");
}

void	pb_rb(t_node **stack_a, t_node **stack_b, t_flags *flags)
{
	push_b(stack_a, stack_b, flags);
	if (*stack_b && (*stack_b)->next)
	{
		if ((*stack_b)->nb < (*stack_b)->next->nb)
			rb(stack_b, flags);
	}
}

void	simple_transfer_to_b(t_node **stack_a, t_node **stack_b, t_flags *flags)
{
	t_min	info;
	int		i;

	while (*stack_a)
	{
		info = get_min(*stack_a);
		if (info.pos == 1)
		{
			sa(*stack_a, flags);
			pb_rb(stack_a, stack_b, flags);
			continue ;
		}
		i = 0;
		if (info.pos <= info.size / 2)
			while (i++ < info.pos)
				ra(stack_a, flags);
		else
			while (i++ < info.size - info.pos)
				rra(stack_a, flags);
		pb_rb(stack_a, stack_b, flags);
	}
}
