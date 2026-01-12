/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 23:57:11 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/12 02:14:20 by rshikder         ###   ########.fr       */
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
			if(cur_a->nb > stack_b->nb && cur_a->nb < best_index)
			{
				best_index = cur_a->nb;
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

void min_top(s_node **stack_a, s_flags *flags)
{
	while((*stack_a)->nb != find_minimum(*stack_a)->nb)
	{
		if (find_minimum(*stack_a)->plus_med)
			ra(stack_a, flags);
		else
			rra(stack_a, flags);
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

void calc_cost_b(s_node *stack_a, s_node *stack_b)
{
	int a_len;
	int b_len;

	a_len = len_stack(stack_a);
	b_len = len_stack(stack_b);
	while(stack_b)
	{
		stack_b->cost = stack_b->index;
		if (!stack_b->plus_med)
			stack_b->cost = b_len - (stack_b->index);
		if (stack_b->target_node)
		{
			if (stack_b->target_node->plus_med)
				stack_b->cost += stack_b->target_node->index;
			else
				stack_b->cost += a_len - (stack_b->target_node->index);
		}
		stack_b = stack_b->next;
	}
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

