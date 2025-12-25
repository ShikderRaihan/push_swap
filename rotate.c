/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:37:02 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/25 20:37:38 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void rotate(s_node **head)
{
	s_node *first;
	s_node *last;
	
	if(*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	*head = first->next;
	(*head)->prev = NULL;
	last = *head;
	while(last->next != NULL)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;	
}

void ra(s_node **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
}

void rb(s_node **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		rotate(stack_b);
		ft_printf("rb\n");
    }
}

void rr(s_node **stack_a, s_node **stack_b)
{
	int i = 0;

    if (*stack_a && (*stack_a)->next)
    {
        rotate(stack_a);
        i = 1;
    }
    if (*stack_b && (*stack_b)->next)
    {
        rotate(stack_b);
        i = 1;
    }
    if (i)
        ft_printf("rr\n");
}
