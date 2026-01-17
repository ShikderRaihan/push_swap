/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwart <cschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:51:58 by cschwart          #+#    #+#             */
/*   Updated: 2026/01/15 14:06:45 by cschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	push_chunk(t_node **stack_a, t_node **stack_b, int min, int max,
	t_flags *flags)
{
	t_node	*target;
	int		len_a;
	int		dist_top;
	int		dist_bottom;

	len_a = len_stack(*stack_a);
	while (1)
	{
		target = find_next_in_chunk(*stack_a, min, max);
		if (!target)
			break ;
		dist_top = distance_to_top(*stack_a, target->nb);
		dist_bottom = distance_to_bottom(*stack_a, target->nb);
		while ((*stack_a)->nb != target->nb)
		{
			if (dist_top <= dist_bottom)
				ra(stack_a, flags);
			else
				rra(stack_a, flags);
		}
		pb(stack_b, stack_a, flags);
		if ((*stack_b)->next && (*stack_b)->nb < (*stack_b)->next->nb)
			sb(*stack_b, flags);
	}
} */

void	move_target_to_top(t_node **stack_a, t_node *target,
	t_flags *flags)
{
	int	dist_top;
	int	dist_bottom;

	dist_top = distance_to_top(*stack_a, target->nb);
	dist_bottom = distance_to_bottom(*stack_a, target->nb);
	while ((*stack_a)->nb != target->nb)
	{
		if (dist_top <= dist_bottom)
			ra(stack_a, flags);
		else
			rra(stack_a, flags);
	}
}

void	push_chunk(t_node **stack_a, t_node **stack_b,
	t_chunk chunk, t_flags *flags)
{
	t_node	*target;

	while (1)
	{
		target = find_next_in_chunk(*stack_a, chunk.min, chunk.max);
		if (!target)
			break ;
		move_target_to_top(stack_a, target, flags);
		pb(stack_b, stack_a, flags);
		if ((*stack_b)->next && (*stack_b)->nb < (*stack_b)->next->nb)
			sb(*stack_b, flags);
	}
}

void	push_back_max(t_node **stack_a, t_node **stack_b, t_flags *flags)
{
	int	max;
	int	dist_top;
	int	dist_bottom;

	while (*stack_b)
	{
		max = find_max(*stack_b);
		dist_top = distance_to_top(*stack_b, max);
		dist_bottom = len_stack(*stack_b) - dist_top;
		while ((*stack_b)->nb != max)
		{
			if (dist_top <= dist_bottom)
				rb(stack_b, flags);
			else
				rrb(stack_b, flags);
		}
		pa(stack_a, stack_b, flags);
	}
}

void	chunk_sort(t_node **stack_a, t_node **stack_b, t_flags *flags)
{
	int	size;
	int	chunk;
	int	min;
	int	max;

	flags->disorder = compute_disorder(*stack_a, flags);
	size = len_stack(*stack_a);
	stack_index(*stack_a);
	if (size <= 100)
		chunk = 20;
	else
		chunk = 45;
	min = 0;
	while (min < size)
	{
		max = min + chunk - 1;
		push_chunk(stack_a, stack_b, (t_chunk){min, max}, flags);
		min += chunk;
	}
	push_back_max(stack_a, stack_b, flags);
	if (flags->bench)
		print_bench(flags, flags->disorder);
}
