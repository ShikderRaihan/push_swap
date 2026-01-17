/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tur_cal_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwart <cschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:50:43 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/15 14:04:02 by cschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_cost(t_node *n, int len)
{
	if (n->plus_med)
		return (n->index);
	return (len - n->index);
}

int	merge_cost(t_node *src, t_node *dst, int cost_s, int cost_d)
{
	if (src->plus_med == dst->plus_med)
	{
		if (cost_s > cost_d)
			return (cost_s);
		return (cost_d);
	}
	return (cost_s + cost_d);
}

void	calc_cost_b(t_node *stack_a, t_node *stack_b)
{
	int	a_len;
	int	b_len;
	int	cost_b;
	int	cost_a;

	a_len = len_stack(stack_a);
	b_len = len_stack(stack_b);
	while (stack_b)
	{
		cost_b = node_cost(stack_b, b_len);
		cost_a = node_cost(stack_b->target_node, a_len);
		stack_b->cost = merge_cost(stack_b, stack_b->target_node, cost_b,
				cost_a);
		stack_b = stack_b->next;
	}
}

void	calc_cost(t_node *stack_a, t_node *stack_b)
{
	int	a_len;
	int	b_len;
	int	cost_a;
	int	cost_b;

	a_len = len_stack(stack_a);
	b_len = len_stack(stack_b);
	while (stack_a)
	{
		cost_a = node_cost(stack_a, a_len);
		cost_b = node_cost(stack_a->target_node, b_len);
		stack_a->cost = merge_cost(stack_a, stack_a->target_node, cost_a,
				cost_b);
		stack_a = stack_a->next;
	}
}
