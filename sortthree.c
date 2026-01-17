/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortthree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwart <cschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:46:33 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/15 14:06:34 by cschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack_a, t_flags *flags)
{
	int	ek;
	int	dui;
	int	tin;

	ek = (*stack_a)->nb;
	dui = (*stack_a)->next->nb;
	tin = (*stack_a)->next->next->nb;
	if ((ek < dui) && (dui < tin))
		return ;
	if ((ek < dui) && (dui > tin) && (ek < tin))
	{
		rra(stack_a, flags);
		sa(*stack_a, flags);
	}
	else if ((ek < dui) && (dui > tin) && (ek > tin))
		rra(stack_a, flags);
	else if ((ek > dui) && (dui < tin) && (ek > tin))
		ra(stack_a, flags);
	else if ((ek > dui) && (dui > tin))
	{
		sa(*stack_a, flags);
		rra(stack_a, flags);
	}
	else
		sa(*stack_a, flags);
}
