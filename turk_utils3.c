/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:37:46 by cschwart          #+#    #+#             */
/*   Updated: 2026/01/17 14:51:11 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	while_cur_b(t_node *stack_a, t_node *stack_b)
// {
// 	t_node	*cur_b;
// 	t_node	*tar_node;
// 	long	best_val;

// 	best_val = LONG_MIN;
// 	tar_node = NULL;
// 	cur_b = stack_b;
// 	while (cur_b)
// 	{
// 		if (cur_b->nb < stack_a->nb && (cur_b->nb - stack_a->nb) > best_val)
// 		{
// 			best_val = (cur_b->nb - stack_a->nb);
// 			tar_node = cur_b;
// 		}
// 		cur_b = cur_b->next;
// 	}
// }

void	aim_node_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*cur_b;
	t_node	*tar_node;
	long	best_val;

	while (stack_a)
	{
		best_val = LONG_MIN;
		tar_node = NULL;
		cur_b = stack_b;
		while (cur_b)
		{
			if (cur_b->nb < stack_a->nb && (cur_b->nb - stack_a->nb) > best_val)
			{
				best_val = (cur_b->nb - stack_a->nb);
				tar_node = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (best_val == LONG_MIN)
			stack_a->target_node = find_max_node(stack_b);
		else
			stack_a->target_node = tar_node;
		stack_a = stack_a->next;
	}
}

// void	aim_node_a(t_node *stack_a, t_node *stack_b)
// {
// 	t_node	*tar_node;
// 	long	best_val;

// 	if (!stack_b)
// 		return ;
// 	while (stack_a)
// 	{
// 		best_val = LONG_MIN;
// 		tar_node = NULL;
// 		while_cur_b(stack_a, stack_b);
// 		if (best_val == LONG_MIN)
// 		{
// 			tar_node = find_max_node(stack_b);
// 			stack_a->target_node = tar_node;
// 		}
// 		else
// 			stack_a->target_node = tar_node;
// 		stack_a = stack_a->next;
// 	}
// }

void	closest_set(t_node *stack)
{
	long	minst_val;
	t_node	*minst_node;
	t_node	*temp;

	if (!stack)
		return ;
	minst_val = LONG_MAX;
	minst_node = stack;
	temp = stack;
	while (temp)
	{
		temp->closest = 0;
		temp = temp->next;
	}
	while (stack)
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
