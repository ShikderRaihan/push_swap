/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwart <cschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:57:53 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/15 14:06:52 by cschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bits_max(t_node *stack_a)
{
	int		bits;
	int		max;
	t_node	*tmp;

	bits = 0;
	max = 0;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->nb > max)
			max = tmp->nb;
		tmp = tmp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	bit_process(t_node **stack_a, t_node **stack_b, t_flags *flags,
	int bits)
{
	int	size;
	int	i;

	size = len_stack(*stack_a);
	i = 0;
	while (i < size)
	{
		if (((*stack_a)->nb >> bits) & 1)
		{
			ra(stack_a, flags);
		}
		else
		{
			pb(stack_b, stack_a, flags);
		}
		i++;
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b, flags);
	}
}

void	complex_sort(t_node **stack_a, t_node **stack_b, t_flags *flags)
{
	int	max_bit;
	int	i;

	i = 0;
	flags->disorder = compute_disorder(*stack_a, flags);
	stack_index(*stack_a);
	max_bit = bits_max(*stack_a);
	while (i < max_bit)
	{
		bit_process(stack_a, stack_b, flags, i);
		i++;
	}
	if (flags->bench)
		print_bench(flags, flags->disorder);
}
