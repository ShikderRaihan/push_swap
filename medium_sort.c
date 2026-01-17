/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwart <cschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:57:53 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/15 14:03:35 by cschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_chunk(int val, int min, int max)
{
	if (val >= min && val <= max)
		return (1);
	return (0);
}

int	find_max(t_node *stack_a)
{
	int	max;

	max = stack_a->nb;
	while (stack_a)
	{
		if (stack_a->nb > max)
			max = stack_a->nb;
		stack_a = stack_a->next;
	}
	return (max);
}

int	distance_to_top(t_node *stack_a, int val)
{
	int	dist;

	dist = 0;
	while (stack_a)
	{
		if (stack_a->nb == val)
			return (dist);
		dist++;
		stack_a = stack_a->next;
	}
	return (dist);
}

int	distance_to_bottom(t_node *stack, int val)
{
	int	len;
	int	top_dist;

	len = len_stack(stack);
	top_dist = distance_to_top(stack, val);
	return (len - top_dist);
}

t_node	*find_next_in_chunk(t_node *stack, int min, int max)
{
	while (stack)
	{
		if (in_chunk(stack->nb, min, max))
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
