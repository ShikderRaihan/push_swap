/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:16:23 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/24 21:36:12 by rshikder         ###   ########.fr       */
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

void sa(s_node *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}


void sb(s_node *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void ss(void)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

void push(s_node **stack_a, s_node **stack_b, char swi)
{
	s_node *tmp;
	
	if(*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	if ((*stack_b) != NULL)
		(*stack_b)->prev = NULL;
	tmp->next = *stack_a;
	if (*stack_a != NULL)
		(*stack_a)->prev = tmp;
	tmp->prev = NULL;
	(*stack_a)= tmp;
	if(swi == 'a')
		ft_printf("pa\n");
	else if(swi == 'b')
		ft_printf("pb\n");
}
