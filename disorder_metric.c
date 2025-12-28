/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 21:48:45 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/28 20:48:45 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float compute_disorder(s_node *stack_a)
{
	int mistakes;
	int total_pairs;
	s_node *i;
	s_node *j;
	
	mistakes = 0;
	total_pairs = 0;
	i = stack_a;
	while(i)
	{
		j = i->next;
		while (j)
			{
				total_pairs += 1;
				if(i->nb > j->nb)
					mistakes += 1;
				j = j->next;
			}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((float)mistakes / (float)total_pairs);
}
void disorder_metric(float dis_order)
{
	int i;
	int j;
	
	i = (int)(dis_order * 100);
	j = ((int)(dis_order * 10000) % 100);
	stderr_printf("Disorder: %d.%d%%\n", i, j);
}
