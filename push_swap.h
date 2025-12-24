#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include "../Libft/libft.h"
#include "../ft_printf/ft_printf.h"

typedef struct p_node
{
	int	nb;
	struct p_node *next;
	struct p_node *prev;
}s_node;

void	insert_af(s_node **stack, int nb);

//handle error

//stack initiation

//nodes initiation

//stack utils

//commands
void swap(s_node *head);
void sa(s_node *stack_a);
void sb(s_node *stack_b);
void ss(void);


//algorithms

#endif