/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:01:36 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/12 01:58:39 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void transfer_to_b(s_node **stack_a, s_node **stack_b, s_flags *flags)
{
	s_node *minst_node;

	minst_node = find_closest(*stack_a);
	if (!minst_node || !minst_node->target_node)
		return ;
	if (minst_node->plus_med && minst_node->target_node->plus_med)
		rotate_rr(stack_a, stack_b, minst_node, flags);
	else if (!(minst_node->plus_med) && !(minst_node->target_node->plus_med))
		rev_rot_rrr(stack_a, stack_b, minst_node, flags);
	pre_push(stack_a, minst_node, flags, 'a');
	pre_push(stack_b, minst_node->target_node, flags, 'b');
	pb(stack_b, stack_a, flags);
}
void transfer_to_a(s_node **stack_a, s_node **stack_b, s_flags *flags)
{
	s_node *minst_node;

	minst_node = find_closest(*stack_b);
	if (!minst_node || !minst_node->target_node)
		return ;
	pre_push(stack_b, minst_node, flags, 'b');
	pre_push(stack_a, minst_node->target_node, flags, 'a');
	pa(stack_a, stack_b, flags);
}

s_node *find_closest(s_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->closest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void pre_push(s_node **stack, s_node *node_top,s_flags *flags, char stack_name)
{
	int max_iterations;
	int iterations;

	if (!node_top || !stack || !(*stack))
		return ;
	max_iterations = len_stack(*stack);
	iterations = 0;
	while(*stack != node_top && iterations < max_iterations)
	{
		if (stack_name == 'a')
		{
			if (node_top->plus_med)
				ra(stack, flags);
			else
				rra(stack, flags);
		}
		else if (stack_name == 'b')
		{
			if (node_top->plus_med)
				rb(stack, flags);
			else
				rrb(stack, flags);
		}
		iterations++;
	}
}

