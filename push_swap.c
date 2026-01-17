/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:40:27 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/17 19:03:29 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_af(t_node **head, int nb)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->nb = nb;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}

void	free_stack(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	while (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
	}
	*stack_a = NULL;
	if (stack_b)
	{
		while (*stack_b)
		{
			temp = *stack_b;
			*stack_b = (*stack_b)->next;
			free(temp);
		}
		*stack_b = NULL;
	}
}
// void choose_adaptive(t_flags *flags)
// {
// 	float disorder;

// 	disorder = compute_disorder(flags);
// }