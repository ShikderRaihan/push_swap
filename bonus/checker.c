/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwart <cschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:21:26 by cschwart          #+#    #+#             */
/*   Updated: 2026/01/15 15:43:26 by cschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_int(char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '-')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/* int	check_dup(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
} */

/* void	executing(char *line, t_node **a, t_node **b, t_flags *flags)
{
	if (!ft_strcmp(line, "sa\n") || !ft_strcmp(line, "sb\n")
		|| !ft_strcmp(line, "ss\n") || !ft_strcmp(line, "pa\n")
		|| !ft_strcmp(line, "pb\n") || !ft_strcmp(line, "ra\n")
		|| !ft_strcmp(line, "rb\n") || !ft_strcmp(line, "rr\n")
		|| !ft_strcmp(line, "rra\n") || !ft_strcmp(line, "rrb\n")
		|| !ft_strcmp(line, "rrr\n"))
	{
		ft_printf("Error\n");
		free(line);
		exit(1);
	}
	execute_swap(line, a, b, flags);
	execute_push(line, a, b, flags);
	execute_rotate(line, a, b, flags);
	execute_rev_rotate(line, a, b, flags);
} */
void	executing(char *line, t_node **a, t_node **b, t_flags *flags)
{
	if (!(!ft_strcmp(line, "sa\n") || !ft_strcmp(line, "sb\n")
			|| !ft_strcmp(line, "ss\n") || !ft_strcmp(line, "pa\n")
			|| !ft_strcmp(line, "pb\n") || !ft_strcmp(line, "ra\n")
			|| !ft_strcmp(line, "rb\n") || !ft_strcmp(line, "rr\n")
			|| !ft_strcmp(line, "rra\n") || !ft_strcmp(line, "rrb\n")
			|| !ft_strcmp(line, "rrr\n")))
	{
		ft_printf("Error\n");
		free(line);
		exit(1);
	}
	execute_swap(line, a, b, flags);
	execute_push(line, a, b, flags);
	execute_rotate(line, a, b, flags);
	execute_rev_rotate(line, a, b, flags);
}

int	is_sorted(t_node *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->nb > stack_a->next->nb)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	check_result(t_node *stack_a, t_node *stack_b)
{
	if (is_sorted(stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
