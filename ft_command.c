/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:16:23 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/25 20:14:53 by rshikder         ###   ########.fr       */
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
	if (stack_a && stack_a->next)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
}


void sb(s_node *stack_b)
{
	if (stack_b && stack_b->next)
	{
		swap(stack_b);
		ft_printf("sb\n");
	}
}

void ss(s_node *stack_a, s_node *stack_b)
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
        ft_printf("ss\n");
}

void push(s_node **stack_a, s_node **stack_b)
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
}

void pa(s_node **stack_a, s_node **stack_b)
{
	if (*stack_b)
	{
		push(stack_a, stack_b);
		ft_printf("pa\n");
	}
}
void pb(s_node **stack_b, s_node **stack_a)
{
	if (*stack_a)
	{
		push(stack_b, stack_a);
		ft_printf("pb\n");
	}
}

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
