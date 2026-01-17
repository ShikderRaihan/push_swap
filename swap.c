/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwart <cschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:36:01 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/15 14:06:32 by cschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void swap(t_node **head)
{
	t_node *no1;
	t_node *no2;
	t_node *no3;

	if(*head == NULL || (*head)->next == NULL)
		return ;
	no1 = *head;
	no2 = (*head)->next;
	no3 = no2->next;

	no2->prev = NULL;
	no2->next = no1;
	no1->prev = no2;
	no1->next = no3;

	if (no3 != NULL)
		no3->prev = no1;
	*head = no2;
} */

/* void sa(t_node **stack_a, t_flags *flags)
{
	if ((*stack_a) && (*stack_a)->next)
	{
		swap(stack_a);
		flags->total++;
		flags->sa++;
		if (!flags->bench)
			ft_printf("sa\n");
	}
} */

/* void sb(t_node **stack_b, t_flags *flags)
{
	if ((*stack_b) && (*stack_b)->next)
	{
		swap(stack_b);
		flags->total++;
		flags->sb++;
		if (!flags->bench)
			ft_printf("sb\n");
	}
} */

/* void ss(t_node **stack_a, t_node **stack_b, t_flags *flags)
{
		int i = 0;

    if ((*stack_a) && (*stack_a)->next)
    {
        swap(stack_a);
        i = 1;
    }
    if ((*stack_b) && (*stack_b)->next)
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
} */

void	swap(t_node *head)
{
	int	tmp;

	if (head == NULL || head->next == NULL)
		return ;
	tmp = head->nb;
	head->nb = head->next->nb;
	head->next->nb = tmp;
}

void	sa(t_node *stack_a, t_flags *flags)
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

void	sb(t_node *stack_b, t_flags *flags)
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

void	ss(t_node *stack_a, t_node *stack_b, t_flags *flags)
{
	int	i;

	i = 0;
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
