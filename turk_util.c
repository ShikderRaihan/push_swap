/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 23:57:11 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/14 15:07:27 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_nodes_b(s_node *stack_a, s_node *stack_b)
{
	update_index(stack_a);
	update_index(stack_b);
	aim_node_b(stack_a, stack_b);
	calc_cost_b(stack_a, stack_b);
	closest_set(stack_b);
}
void aim_node_b(s_node *stack_a, s_node *stack_b)
{
	s_node *cur_a;
	s_node *tar_node;
	long best_index;
	
	while(stack_b)
	{
		best_index = LONG_MAX;
		tar_node = NULL;
		cur_a = stack_a;
		while (cur_a)
		{
			if(cur_a->nb > stack_b->nb && (cur_a->nb - stack_b->nb) < best_index)
			{
				best_index = cur_a->nb - stack_b->nb;
				tar_node = cur_a;
			}
			cur_a = cur_a->next;
		}	
		if (best_index == LONG_MAX)
			stack_b->target_node = find_minimum(stack_a);
		else
			stack_b->target_node = tar_node;
		stack_b = stack_b->next;
	}
}

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

void final_sort(s_node **stack_a, s_flags *flags)
{
	s_node *min_node;
	int len;
	int iterations;

	if (!stack_a || !*stack_a)
		return ;
	update_index(*stack_a);
	min_node = find_minimum(*stack_a);
	if (!min_node)
		return ;
	len = len_stack(*stack_a);
	iterations = 0;
	while(*stack_a && (*stack_a)->nb != min_node->nb && iterations < len)
	{
		if (min_node->plus_med)
			ra(stack_a, flags);
		else
			rra(stack_a, flags);
		iterations++;
	}
}

