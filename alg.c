/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:32:57 by cschwart          #+#    #+#             */
/*   Updated: 2025/12/30 23:25:42 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void simple_sort(s_node *stack_a, s_flags *flags)
{
	int		booln;
	s_node	*stacked;

	if (!stack_a || !stack_a->next)
		return ;
	booln = 1;
	while (booln)
	{
		booln = 0;
		stacked = stack_a;
		while (stacked && stacked->next)
		{
			if (stacked->nb > stacked->next->nb)
			{
				sa(stacked, flags);
				booln = 1;
			}
			stacked = stacked->next;
		}
	}
	if (flags->bench)
		print_bench(flags, flags->disorder);
}
