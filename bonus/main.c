/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwart <cschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:02:09 by cschwart          #+#    #+#             */
/*   Updated: 2026/01/15 14:05:51 by cschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_val(t_node **stack, int val)
{
	t_node	*new;
	t_node	*current;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->nb = val;
	new->next = NULL;
	new->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;
}

t_flags	*init_flags(void)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	ft_bzero(flags, sizeof(t_flags));
	return (flags);
}

t_node	*init_stack(int argc, char **argv)
{
	t_node			*stack;
	int				val;
	int				i;

	stack = NULL;
	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
	}
	while (argv[i])
	{
		if (!is_int(argv[i]))
		{
			stderr_printf("Error.\n");
			return (NULL);
		}
		val = ft_atoi(argv[i]);
		push_val(&stack, val);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_flags	*flags;
	char	*line;

	if (argc < 2)
		return (0);
	flags = init_flags();
	if (!flags)
		return (1);
	flags->bench = 1;
	stack_a = init_stack(argc, argv);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		executing(line, &stack_a, &stack_b, flags);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	check_result(stack_a, stack_b);
	free(flags);
	return (0);
}
