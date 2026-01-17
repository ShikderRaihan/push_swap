/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 23:49:28 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/17 16:15:03 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bench(t_flags *flags, float disorder)
{
	if (flags->bench)
	{
		stderr_printf("\n=== BENCH ===\n");
		disorder_metric(disorder);
		//strategy name;
		stderr_printf("Total ops: %d   →   ", flags->total);
		stderr_printf("sa: %d   ", flags->sa);
		stderr_printf("sb: %d   ", flags->sb);
		stderr_printf("ss: %d   ", flags->ss);
		stderr_printf("pa: %d   ", flags->pa);
		stderr_printf("pb: %d   ", flags->pb);
		stderr_printf("ra: %d   ", flags->ra);
		stderr_printf("rb: %d   ", flags->rb);
		stderr_printf("rr: %d   ", flags->rr);
		stderr_printf("rra: %d   ", flags->rra);
		stderr_printf("rrb: %d   ", flags->rrb);
		stderr_printf("rrr: %d\n\n", flags->rrr);
	}
}
