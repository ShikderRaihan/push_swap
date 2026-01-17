/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwart <cschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:28:27 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/15 14:05:33 by cschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int *stack_to_intarr(t_node *stack_a, int size)
{
	int *arrint;
	int i;
	
	arrint = NULL;
	i = 0;
	
	while(stack_a)
	{
		arrint[i] = stack_a->nb;
		stack_a = stack_a->next;
		i++;
	}
	return (arrint);
}
void simple_sort(t_node **stack_a, t_flags *flags)
{
	// t_node *tmp;
	// t_node *tmp1;
	
	// tmp = stack_a;
	while((*stack_a)->next)
	{
		//tmp1 = stack_a->next;
		while((*stack_a)->next->next)
		{
			if ((*stack_a)->nb > (*stack_a)->next->nb)
				sa(stack_a, flags);
			(*stack_a)->next = (*stack_a)->next->next;
		}
		(*stack_a) = (*stack_a)->next;
	}
	print_bench(flags);
} */

/* t_node	*find_minimum(t_node *stack)
{
	t_node	*min;
	t_node	*curr;

	min = stack;
	curr = stack->next;
	if (!stack)
		return (NULL);
	while (curr)
	{
		if (curr->nb < min->nb)
			min = curr;
		curr = curr->next;
	}
	return (min);
} */

int	find_node_index(t_node *stack, t_node *node)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = stack;
	while (curr && curr != node)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

int	stack_size(t_node *stack)
{
	int		size;
	t_node	*curr;

	size = 0;
	curr = stack;
	while (curr)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}

t_min	get_min(t_node *stack)
{
	t_min	info;
	t_node	*cur;
	int		i;

	info.min = stack;
	info.pos = 0;
	info.size = 0;
	cur = stack;
	i = 0;
	while (cur)
	{
		if (cur->nb < info.min->nb)
		{
			info.min = cur;
			info.pos = i;
		}
		cur = cur->next;
		i++;
		info.size++;
	}
	return (info);
}

void	simple_sort(t_node **stack_a, t_node **stack_b, t_flags *flags)
{
	flags->disorder = compute_disorder(*stack_a, flags);
	simple_transfer_to_b(stack_a, stack_b, flags);
	while (*stack_b)
	{
		if ((*stack_b)->next && (*stack_b)->nb < (*stack_b)->next->nb)
			sb(*stack_b, flags);
		push_a(stack_a, stack_b, flags);
	}
	if (flags->bench)
		print_bench(flags, flags->disorder);
}
