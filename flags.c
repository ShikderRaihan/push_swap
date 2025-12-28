/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:07:16 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/28 23:49:38 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void read_flags(int *ac, char ***av, s_flags *flags)
{
    int i = 1;

    while (i < *ac)
    {
        if (check_flag((*av)[i], flags))
            rem_flags(ac, av, i); 
        else
            i++;
    }
}

static int check_flag(char *arg, s_flags *flags)
{
    if (ft_strncmp(arg, "--bench", 7) == 0)
        flags->bench = 1;
    else if (ft_strncmp(arg, "--simple", 8) == 0)
        flags->algo = 0;
    else if (ft_strncmp(arg, "--medium", 8) == 0)
        flags->algo = 1;
    else if (ft_strncmp(arg, "--complex", 9) == 0)
        flags->algo = 2;
    else if (ft_strncmp(arg, "--adaptive", 10) == 0)
        flags->algo = -1;
    else
        return (0); 
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
