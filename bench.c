/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 23:49:28 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/28 23:49:58 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_bench()
{
	stderr_printf("=== BENCH ===\n");
	disorder_metric(compute_disorder);
	stderr_printf("Total ops: %d\n\n", s_flags->total);
	//strategy
	stderr_printf("sa: %d\n", s_flags->sa);
	stderr_printf("sb: %d\n", s_flags->sb);
	stderr_printf("ss: %d\n", s_flags->ss);
	stderr_printf("pa: %d\n", s_flags->pa);
	stderr_printf("pb: %d\n", s_flags->pb);
	stderr_printf("ra: %d\n", s_flags->ra);
	stderr_printf("rb: %d\n", s_flags->rb);
	stderr_printf("rr: %d\n", s_flags->rr);
	stderr_printf("rra: %d\n", s_flags->rra);
	stderr_printf("rrb: %d\n", s_flags->rrb);
	stderr_printf("rrr: %d\n", s_flags->rrr);
}
