/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 21:13:04 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/25 21:23:10 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int err_rep(s_node *stack_a, int value)
{
	while(stack_a)
	{
		if (stack_a->nb == value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

// int err_rep(char **av, int value)
// {
// 	while(*av)
// 	{
// 		if (*av == value)
// 			return (1);
// 		(*av)++;
// 	}
// 	return (0);
// }

