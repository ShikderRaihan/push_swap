/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:57:53 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/10 22:34:08 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int in_chunk (int val, int min, int max)
{
	if (val >= min && val <= max)
		return (1);
	return (0);
}

int	find_max(s_node *stack_a)
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
int distance_to_top(s_node *stack_a, int val)
{
    int dist = 0;

    while (stack_a)
    {
        if (stack_a->nb == val)
            return dist;
        dist++;
        stack_a = stack_a->next;
    }
    return (dist);
}

int distance_to_bottom(s_node *stack, int val)
{
    int len = len_stack(stack);
    int top_dist = distance_to_top(stack, val);
    return len - top_dist;
}

s_node *find_next_in_chunk(s_node *stack, int min, int max)
{
    while (stack)
    {
        if (in_chunk(stack->nb, min, max))
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

void	push_chunk(s_node **stack_a, s_node **stack_b, int min, int max, s_flags *flags)
{
	s_node	*target;
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
}

void push_back_max(s_node **stack_a, s_node **stack_b, s_flags *flags)
{
    int max;
    int dist_top;
    int dist_bottom;

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

void	chunk_sort(s_node **stack_a, s_node **stack_b, s_flags *flags)
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
		push_chunk(stack_a, stack_b, min, max, flags);
		min += chunk;
	}
	push_back_max(stack_a, stack_b, flags);
	if (flags->bench)
		print_bench(flags, flags->disorder);
}
