/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 23:49:28 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/29 20:31:45 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_bench(s_flags *flags)
{
	if(flags->bench)
	{
		stderr_printf("=== BENCH ===\n");
		disorder_metric(flags->disorder);
		stderr_printf("Total ops: %d\n\n", flags->total);
		//strategy
		stderr_printf("sa: %d\n", flags->sa);
		stderr_printf("sb: %d\n", flags->sb);
		stderr_printf("ss: %d\n", flags->ss);
		stderr_printf("pa: %d\n", flags->pa);
		stderr_printf("pb: %d\n", flags->pb);
		stderr_printf("ra: %d\n", flags->ra);
		stderr_printf("rb: %d\n", flags->rb);
		stderr_printf("rr: %d\n", flags->rr);
		stderr_printf("rra: %d\n", flags->rra);
		stderr_printf("rrb: %d\n", flags->rrb);
		stderr_printf("rrr: %d\n", flags->rrr);
	}
}
