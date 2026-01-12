/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwart <cschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:28:27 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/09 16:37:49 by cschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int *stack_to_intarr(s_node *stack_a, int size)
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
void simple_sort(s_node **stack_a, s_flags *flags)
{
	// s_node *tmp;
	// s_node *tmp1;
	
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

s_node	*find_minimum(s_node *stack)
{
	s_node	*min;
	s_node	*curr;

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
}

int	find_node_index(s_node *stack, s_node *node)
{
	int		i;
	s_node	*curr;

	i = 0;
	curr = stack;
	while (curr && curr != node)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

int	stack_size(s_node *stack)
{
	int		size;
	s_node	*curr;

	size = 0;
	curr = stack;
	while (curr)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}

t_min	get_min(s_node *stack)
{
	t_min	info;
	s_node	*cur;
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

void	pb_rb(s_node **stack_a, s_node **stack_b, s_flags *flags)
{
	push_b(stack_a, stack_b, flags);
	if (*stack_b && (*stack_b)->next)
	{
		if ((*stack_b)->nb < (*stack_b)->next->nb)
			rb(stack_b, flags);
	}
}

void	transfer_to_b(s_node **stack_a, s_node **stack_b, s_flags *flags)
{
	t_min	info;
	int		i;

	while (*stack_a)
	{
		info = get_min(*stack_a);
		if (info.pos == 1)
			sa(*stack_a, flags);
		if (info.pos <= 1)
		{
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

void	simple_sort(s_node **stack_a, s_node **stack_b, s_flags *flags)
{
	transfer_to_b(stack_a, stack_b, flags);
	while (*stack_b)
	{
		if ((*stack_b)->next && (*stack_b)->nb < (*stack_b)->next->nb)
			sb(*stack_b, flags);
		push_a(stack_a, stack_b, flags);
	}
	print_bench(flags);
}
