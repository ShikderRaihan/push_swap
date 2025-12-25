/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:38:20 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/25 20:38:48 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void reverse_rotate(s_node **head)
{
	s_node *first;
	s_node *last;
	
	if(*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	last = *head;
	while(last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*head = last;
}

void rra(s_node **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		reverse_rotate(stack_a);
		ft_printf("rra\n");
	}
}

void rrb(s_node **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		reverse_rotate(stack_b);
		ft_printf("rrb\n");
    }
}

void rrr(s_node **stack_a, s_node **stack_b)
{
	int i = 0;

    if (*stack_a && (*stack_a)->next)
    {
        reverse_rotate(stack_a);
        i = 1;
    }
    if (*stack_b && (*stack_b)->next)
    {
        reverse_rotate(stack_b);
        i = 1;
    }
    if (i)
        ft_printf("rrr\n");
}
