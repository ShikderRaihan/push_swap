/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwart <cschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:22:03 by cschwart          #+#    #+#             */
/*   Updated: 2026/01/15 14:50:07 by cschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "../push_swap.h"
# include "../get_next_line/get_next_line.h"

void	check_result(t_node *stack_a, t_node *stack_b);
t_flags	*init_flags(void);
t_node	*init_stack(int argc, char **argv);
int		is_int(char *s);
int		is_sorted(t_node *stack_a);
void	push_val(t_node **stack, int val);

// EXECUTING
void	executing(char *line, t_node **a, t_node **b, t_flags *flags);
void	execute_swap(char *line, t_node **a, t_node **b, t_flags *flags);
void	execute_push(char *line, t_node **a, t_node **b, t_flags *flags);
void	execute_rotate(char *line, t_node **a, t_node **b, t_flags *flags);
void	execute_rev_rotate(char *line, t_node **a, t_node **b, t_flags *flags);

#endif
