/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:07:16 by rshikder          #+#    #+#             */
/*   Updated: 2026/01/17 18:26:08 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_flags(int *ac, char ***av, t_flags *flags)
{
	int	i;

	i = 1;
	while (i < *ac)
	{
		if (ft_strcmp((*av)[i], "--bench") == 0)
		{
			flags->bench = 1;
			rem_flags(ac, av, i);
		}
		else if (check_flag((*av)[i], flags))
			rem_flags(ac, av, i);
		else
			i++;
	}
}

int	check_flag(char *av, t_flags *flags)
{
	if (ft_strcmp(av, "--simple") == 0)
		flags->algo = 0;
	else if (ft_strcmp(av, "--medium") == 0)
		flags->algo = 1;
	else if (ft_strcmp(av, "--complex") == 0)
		flags->algo = 2;
	else if (ft_strcmp(av, "--adaptive") == 0)
		flags->algo = -1;
	else
		return (0);
	if (flags->algo_set)
		show_err(0, &av, NULL, false);
	flags->algo_set = 1;
	return (1);
}

void	sort(t_node **stack_a, t_node **stack_b, t_flags *flags)
{
	if (flags->algo == 0)
		simple_sort(stack_a, stack_b, flags);
	else if (flags->algo == 1)
		chunk_sort(stack_a, stack_b, flags);
	else if (flags->algo == 2)
		complex_sort(stack_a, stack_b, flags);
	else if (flags->algo == -1 || !flags->algo)
		turk_sort(stack_a, stack_b, flags);
}

void	rem_flags(int *ac, char ***av, int index)
{
	int	i;

	i = index;
	while (i < *ac - 1)
	{
		(*av)[i] = (*av)[i + 1];
		i++;
	}
	(*av)[*ac - 1] = NULL;
	(*ac)--;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
