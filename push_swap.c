/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:40:27 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/31 00:53:40 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_af(s_node **head, int nb)
{
	s_node	*new_node;
	s_node	*current;

	new_node = malloc(sizeof(s_node));
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

void free_stack(s_node *stack_a)
{
	s_node *tmp;
	
	while(stack_a)
	{
		tmp = stack_a->next;
		free (stack_a);
		stack_a = tmp;
	}
}
