/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:58:07 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/17 14:49:57 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max_node(t_node *stack)
{
	t_node	*max_node;

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

/* void	turk_sort(t_node **stack_a, t_node **stack_b, t_flags *flags)
{
	int	len;

	len = len_stack(*stack_a);
	if (len <= 1 || ft_sorted(*stack_a))
		return ;
	if (len == 2)
	{
		if ((*stack_a)->nb > (*stack_a)->next->nb)
			sa(*stack_a, flags);
		return ;
	}
	if (len > 3 && !ft_sorted(*stack_a))
	{
		pb(stack_b, stack_a, flags);
		len--;
	}
	if (len > 3 && !ft_sorted(*stack_a))
	{
		pb(stack_b, stack_a, flags);
		len--;
	}
	while (len > 3 && !ft_sorted(*stack_a))
	{
		fill_nodes_a(*stack_a, *stack_b);
		transfer_to_b(stack_a, stack_b, flags);
		len--;
	}
	sort_three(stack_a, flags);
	while (*stack_b)
	{
		fill_nodes_b(*stack_a, *stack_b);
		transfer_to_a(stack_a, stack_b, flags);
	}
	final_sort(stack_a, flags);
	if (flags->bench)
		print_bench(flags, flags->disorder);
} */

void	push_and_sort_a(t_node **stack_a, t_node **stack_b, t_flags *flags)
{
	int	len;

	len = len_stack(*stack_a);
	if (len > 3 && !ft_sorted(*stack_a))
	{
		pb(stack_b, stack_a, flags);
		len--;
	}
	if (len > 3 && !ft_sorted(*stack_a))
	{
		pb(stack_b, stack_a, flags);
		len--;
	}
	while (len > 3 && !ft_sorted(*stack_a))
	{
		fill_nodes_a(*stack_a, *stack_b);
		transfer_to_b(stack_a, stack_b, flags);
		len--;
	}
	sort_three(stack_a, flags);
}

void	turk_sort(t_node **stack_a, t_node **stack_b, t_flags *flags)
{
	int	len;

	len = len_stack(*stack_a);
	if (len <= 1 || ft_sorted(*stack_a))
		return ;
	if (len == 2)
	{
		if ((*stack_a)->nb > (*stack_a)->next->nb)
			sa(*stack_a, flags);
		return ;
	}
	push_and_sort_a(stack_a, stack_b, flags);
	while (*stack_b)
	{
		fill_nodes_b(*stack_a, *stack_b);
		transfer_to_a(stack_a, stack_b, flags);
	}
	final_sort(stack_a, flags);
	if (flags->bench)
		print_bench(flags, flags->disorder);
}

void	update_index(t_node *stack)
{
	int	x;
	int	med;

	x = 0;
	if (!stack)
		return ;
	med = (len_stack(stack) + 1) / 2;
	while (stack)
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

void	fill_nodes_a(t_node *stack_a, t_node *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	update_index(stack_a);
	update_index(stack_b);
	aim_node_a(stack_a, stack_b);
	calc_cost(stack_a, stack_b);
	closest_set(stack_a);
}
