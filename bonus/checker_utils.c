/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwart <cschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:15:17 by cschwart          #+#    #+#             */
/*   Updated: 2026/01/15 14:40:10 by cschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_swap(char *line, t_node **a, t_node **b, t_flags *flags)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(*a, flags);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(*b, flags);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(*a, *b, flags);
	else
		return ;
}

void	execute_push(char *line, t_node **a, t_node **b, t_flags *flags)
{
	if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b, flags);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(b, a, flags);
	else
		return ;
}

void	execute_rotate(char *line, t_node **a, t_node **b, t_flags *flags)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ra(a, flags);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b, flags);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b, flags);
	else
		return ;
}

void	execute_rev_rotate(char *line, t_node **a, t_node **b, t_flags *flags)
{
	if (ft_strcmp(line, "rra\n") == 0)
		rra(a, flags);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b, flags);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b, flags);
	else
		return ;
}
