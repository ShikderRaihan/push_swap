/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:36:01 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/28 23:34:23 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void swap(s_node **head)
// {
// 	s_node *no1;
// 	s_node *no2;
// 	s_node *no3;
	
// 	if(*head == NULL || (*head)->next == NULL)
// 		return ;
// 	no1 = *head;
// 	no2 = (*head)->next;
// 	no3 = no2->next;

// 	no2->prev = NULL;
// 	no2->next = no1;
// 	no1->prev = no2;
// 	no1->next = no3;

// 	if (no3 != NULL)
// 		no3->prev = no1;
// 	*head = no2;
// }

void swap(s_node *head)
{
	int tmp;
	
	if(head == NULL || head->next == NULL)
		return ;
	tmp = head->nb;
	head->nb = head->next->nb;
	head->next->nb = tmp;
}

void sa(s_node *stack_a, s_flags *flags)
{
	if (stack_a && stack_a->next)
	{
		swap(stack_a);
		flags->total++;
		flags->sa++;
		if (!flags->bench)
			ft_printf("sa\n");
	}
}


void sb(s_node *stack_b, s_flags *flags)
{
	if (stack_b && stack_b->next)
	{
		swap(stack_b);
		flags->total++;
		flags->sb++;
		if (!flags->bench)
			ft_printf("sb\n");
	}
}

void ss(s_node *stack_a, s_node *stack_b, s_flags *flags)
{
		int i = 0;

    if (stack_a && stack_a->next)
    {
        swap(stack_a);
        i = 1;
    }
    if (stack_b && stack_b->next)
    {
        swap(stack_b);
        i = 1;
    }
    if (i)
	{
       	flags->total++;
		flags->ss++;
		if (!flags->bench)
			ft_printf("ss\n");
	}
}
