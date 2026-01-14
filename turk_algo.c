/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:58:07 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/14 15:06:59 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_node	*find_max_node(s_node *stack)
{
	s_node	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (stack->nb > max_node->nb)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

void turk_sort(s_node **stack_a, s_node **stack_b, s_flags *flags)
{
	int len;
	
	len = len_stack(*stack_a);
	if (len <= 1 || ft_sorted(*stack_a))
		return ;
	if (len == 2)
	{
		if ((*stack_a)->nb > (*stack_a)->next->nb)
			sa(*stack_a, flags);
		return ;
	}
	if(len > 3 && !ft_sorted(*stack_a))
	{
		pb(stack_b, stack_a, flags);
		len--;
	}
	if(len > 3 && !ft_sorted(*stack_a))
	{
		pb(stack_b, stack_a, flags);
		len--;
	}
	while(len > 3 && !ft_sorted(*stack_a))
	{
		fill_nodes_a(*stack_a, *stack_b);
		transfer_to_b(stack_a, stack_b, flags);
		len--;
	}
	sort_three(stack_a, flags);
	while(*stack_b)
	{
		fill_nodes_b(*stack_a, *stack_b);
		transfer_to_a(stack_a, stack_b, flags);
	}
	final_sort(stack_a, flags);
	if (flags->bench)
		print_bench(flags, flags->disorder);
}
void update_index(s_node *stack)
{
	int x;
	int med;

	x = 0;
	if (!stack)
		return ;
	med = (len_stack(stack) + 1) / 2;
	while(stack)
	{
		stack->index = x;
		if (x <= med)
			stack->plus_med = 1;
		else
			stack->plus_med = 0;
		stack = stack->next;
		x++;
	}
}

void fill_nodes_a(s_node *stack_a, s_node *stack_b)
{
	update_index(stack_a);
	update_index(stack_b);
	aim_node_a(stack_a, stack_b);
	calc_cost(stack_a, stack_b);
	closest_set(stack_a);
}
void aim_node_a(s_node *stack_a, s_node *stack_b)
{
	s_node *cur_b;
	s_node *tar_node;
	long best_val;
	
	if (!stack_b)
		return ;
	while(stack_a)
	{
		best_val = LONG_MIN;
		tar_node = NULL;
		cur_b = stack_b;
		while (cur_b)
		{
			if(cur_b->nb < stack_a->nb && (cur_b->nb - stack_a->nb) > best_val)
			{
				best_val = (cur_b->nb - stack_a->nb);
				tar_node = cur_b;
			}
			cur_b = cur_b->next;
		}	
		if (best_val == LONG_MIN)
		{
			tar_node = find_max_node(stack_b);
			stack_a->target_node = tar_node;
		}
		else
			stack_a->target_node = tar_node;
		stack_a = stack_a->next;
	}
}

void closest_set(s_node *stack)
{
	long minst_val;
	s_node *minst_node;
	s_node *temp;

	if(!stack)
		return ;
	minst_val = LONG_MAX;
	minst_node = stack;
	temp = stack;
	while(temp)
	{
		temp->closest = 0;
		temp = temp->next;
	}
	while(stack)
	{
		if (stack->cost < minst_val)
		{
			minst_val = stack->cost;
			minst_node = stack;
		}
		stack = stack->next;
	}
	if (minst_node)
		minst_node->closest = 1;
}

