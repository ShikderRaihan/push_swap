/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:28:27 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/29 22:04:59 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int *stack_to_intarr(s_node *stack_a, int size)
// {
// 	int *arrint;
// 	int i;
	
// 	arrint = NULL;
// 	i = 0;
	
// 	while(stack_a)
// 	{
// 		arrint[i] = stack_a->nb;
// 		stack_a = stack_a->next;
// 		i++;
// 	}
// 	return (arrint);
// }
// void simple_sort(s_node **stack_a, s_flags *flags)
// {
// 	// s_node *tmp;
// 	// s_node *tmp1;
	
// 	// tmp = stack_a;
// 	while((*stack_a)->next)
// 	{
// 		//tmp1 = stack_a->next;
// 		while((*stack_a)->next->next)
// 		{
// 			if ((*stack_a)->nb > (*stack_a)->next->nb)
// 				sa(stack_a, flags);
// 			(*stack_a)->next = (*stack_a)->next->next;
// 		}
// 		(*stack_a) = (*stack_a)->next;
// 	}
// 	print_bench(flags);
// }


void simple_sort(s_node *stack_a, s_flags *flags)
{
	// s_node *tmp;
	// s_node *tmp1;
	
	// tmp = stack_a;
		//tmp1 = stack_a->next;
		while(stack_a)
		{
			if (stack_a->nb > stack_a->next->nb)
				swap(stack_a);
			stack_a = stack_a->next;
		}
	print_bench(flags);
}
