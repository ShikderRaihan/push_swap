/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:56:56 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/05 21:59:51 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_values_array(s_node *stack, int *arr)
{
	int	i;

	i = 0;
	while (stack)
	{
		arr[i] = stack->nb;
		i++;
		stack = stack->next;
	}
}
int	compute_index(int *arr, int total, int value)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < total)
	{
		if (arr[i] < value)
			index++;
		i++;
	}
	return (index);
}
void	assign_indices(s_node *stack, int *arr, int total)
{
	while (stack)
	{
		stack->nb = compute_index(arr, total, stack->nb);
		stack = stack->next;
	}
}
void	stack_index(s_node *stack_a)
{
	int		*values;
	int		size;

	size = len_stack(stack_a);
	values = malloc(sizeof(int) * size);
	if (!values)
		return ;
	fill_values_array(stack_a, values);
	assign_indices(stack_a, values, size);
	free(values);
}
