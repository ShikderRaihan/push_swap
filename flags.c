/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:07:16 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/29 18:44:45 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void read_flags(int *ac, char ***av, s_flags *flags)
{
    int i;
	
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

int check_flag(char *av, s_flags *flags)
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
        show_err(0);
    flags->algo_set = 1;
    return (1);
}

void rem_flags(int *ac, char ***av, int index)
{
	int i;

	i = index;
	while (i < *ac - 1)
	{
		(*av)[i] = (*av)[i + 1];
		i++;
	}
	(*av)[*ac - 1] = NULL;
	(*ac)--;
}
int     ft_strcmp(char *s1, char *s2)
{
        int     i;

        i = 0;
        while (s1[i] == s2[i] && s1[i] != '\0')
        {
                i++;
        }
        return (s1[i] - s2[i]);
}
