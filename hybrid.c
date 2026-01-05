/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hybrid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:18:56 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/05 22:32:51 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_range(int val, int min, int max)
{
	if (val >= min && val <= max)
		return (1);
	return (0);
}
int	get_hybrid_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}
void	hybrid_push_range (s_node **a,s_node **b, int min, int max, s_flags *flags)
{
	int	size;
	int	mid;

	size = len_stack(*a);
	mid = min + ((max - min) / 2);
	while (size > 0)
	{
		if (is_in_range((*a)->nb, min, max))
		{
			pb(b, a, flags);
			if ((*b)->nb < mid)
				rb(b, flags);
		}
		else
			ra(a, flags);
		size--;
	}
}

void	hybrid_push_all_ranges(s_node **a, s_node **b, s_flags *flags)
{
	int	size;
	int	chunk;
	int	min;
	int	max;

	size = len_stack(*a);
	chunk = get_hybrid_chunk_size(size);
	min = 0;
	while (min < size)
	{
		max = min + chunk - 1;
		hybrid_push_range(a, b, min, max, flags);
		min += chunk;
	}
}
int	find_max_index(s_node *b)
{
	int	max;

	max = b->nb;
	while (b)
	{
		if (b->nb > max)
			max = b->nb;
		b = b->next;
	}
	return (max);
}
int	get_distance_to_top(s_node *s, int val)
{
	int	dist;

	dist = 0;
	while (s)
	{
		if (s->nb == val)
			return (dist);
		dist++;
		s = s->next;
	}
	return (0);
}
void	hybrid_push_back(s_node **a, s_node **b, s_flags *flags)
{
	int	max;
	int	dist;
	int	len;

	while (*b)
	{
		max = find_max_index(*b);
		dist = get_distance_to_top(*b, max);
		len = len_stack(*b);
		while ((*b)->nb != max)
		{
			if (dist > len / 2)
				rrb(b, flags);
			else
				rb(b, flags);
		}
		pa(a, b, flags);
	}
}
void	hybrid_chunk_sort(s_node **a, s_node **b, s_flags *flags)
{
	stack_index(*a);
	hybrid_push_all_ranges(a, b, flags);
	hybrid_push_back(a, b, flags);
	if (flags->bench)
		print_bench(flags, flags->disorder);
}
