/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hybrid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:18:56 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/12 00:26:14 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted_in_place(s_node *a, int min, int max)
{
    int prev = -1;
    while (a)
    {
        if (a->nb >= min && a->nb <= max)
        {
            if (prev != -1 && a->nb < prev)
                return (0);
            prev = a->nb;
        }
        a = a->next;
    }
    return (1);
}
int already_at_bottom(s_node *a, int min, int max)
{
    s_node *tmp = a;
    while (tmp->next)
        tmp = tmp->next;
    return (tmp->nb >= min && tmp->nb <= max);
}


int	range_exists(s_node *a, int min, int max)
{
	while (a)
	{
		if (a->nb >= min && a->nb <= max)
			return (1);
		a = a->next;
	}
	return (0);
}

int	move_cost(s_node *a, int val)
{
	int	dist;
	int	size;

	size = len_stack(a);
	dist = distance_to_top(a, val);
	if (dist > size / 2)
		return (size - dist);
	return (dist);
}

int	find_cheapest_in_range(s_node *a, int min, int max)
{
	int	best;
	int	best_cost;
	int	cost;

	best_cost = -1;
	while (a)
	{
		if (a->nb >= min && a->nb <= max)
		{
			cost = move_cost(a, a->nb);
			if (best_cost == -1 || cost < best_cost)
			{
				best = a->nb;
				best_cost = cost;
			}
		}
		a = a->next;
	}
	return (best);
}

void	rotate_a_to_top(s_node **a, int val, s_flags *f)
{
	int	dist;
	int	size;

	size = len_stack(*a);
	dist = distance_to_top(*a, val);
	if (dist <= size / 2)
	{
		while ((*a)->nb != val)
			ra(a, f);
	}
	else
	{
		while ((*a)->nb != val)
			rra(a, f);
	}
}
void	push_chunk_smart(s_node **a, s_node **b, int min, int max, s_flags *f)
{
	int	target;

	while (range_exists(*a, min, max))
	{
		target = find_cheapest_in_range(*a, min, max);
		rotate_a_to_top(a, target, f);
		pb(b, a, f);
		if ((*b)->nb < min + (max - min) / 2)
			rb(b, f);
	}
}



void	rotate_b_to_top(s_node **b, int val, s_flags *f)
{
	int	dist;
	int	size;

	size = len_stack(*b);
	dist = distance_to_top(*b, val);
	if (dist <= size / 2)
	{
		while ((*b)->nb != val)
			rb(b, f);
	}
	else
	{
		while ((*b)->nb != val)
			rrb(b, f);
	}
}
void	push_back_to_a(s_node **a, s_node **b, s_flags *f)
{
	int	max;

	while (*b)
	{
		max = find_max(*b);
		rotate_b_to_top(b, max, f);
		pa(a, b, f);
	}
}
void	sort_big(s_node **a, s_node **b, s_flags *flags)
{
	int	size;
	int	chunk;
	int	min;
	int	max;

	stack_index(*a);
	size = len_stack(*a);
	if (size <= 100)
		chunk = 25;
	else
		chunk = 60;
	min = 0;
	while (min < size)
	{
		max = min + chunk - 1;
		if (max >= size)
			max = size - 1;
		push_chunk_smart(a, b, min, max, flags);
		min += chunk;
	}
	push_back_to_a(a, b, flags);
	if (flags->bench)
		print_bench(flags, flags->disorder);
}
