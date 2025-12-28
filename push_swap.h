#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include "../Libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "stderr_printf/stderr_printf.h"

typedef struct p_node
{
	int	nb;
	struct p_node *next;
	struct p_node *prev;
}s_node;

typedef struct t_flags
{
	int total;
	int bench;
	int algo;
	int sa;
	int sb;
	int ss;
	int pa;
	int pb;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
} s_flags;

void	insert_af(s_node **stack, int nb);

//handle error
int err_dup(s_node *stack_a, int value);
int err_over_flow(char *av);
int err_inval_char(char *av);
void show_err(int x);
void	check_input(s_node *stack_a, char *av);
//stack initiation
int ft_sorted(s_node *stack_a);
int len_stack(s_node *stack_a);
long	ft_atol(const char *nptr);
float compute_disorder(s_node *stack_a);
void disorder_metric(float dis_order);
//nodes initiation

//stack utils

//commands
void swap(s_node *head);
void sa(s_node *stack_a);
void sb(s_node *stack_b);
void ss(s_node *stack_a, s_node *stack_b);
void push(s_node **stack_a, s_node **stack_b);
void pa(s_node **stack_a, s_node **stack_b);
void pb(s_node **stack_b, s_node **stack_a);
void rotate(s_node **head);
void ra(s_node **stack_a);
void rb(s_node **stack_b);
void rr(s_node **stack_a, s_node **stack_b);
void reverse_rotate(s_node **head);
void rra(s_node **stack_a);
void rrb(s_node **stack_b);
void rrr(s_node **stack_a, s_node **stack_b);
//algorithms

#endif