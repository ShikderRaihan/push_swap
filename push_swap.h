#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include "../Libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "stderr_printf/stderr_printf.h"

typedef struct t_node
{
	int	nb;
	struct t_node *next;
	struct t_node *prev;
}s_node;

typedef struct t_flags
{
	int total;
	int bench;
	int algo;
	int algo_set;
	float disorder;
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
void	free_stack(s_node **stack);

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
float compute_disorder(s_node *stack_a, s_flags *flags);
void disorder_metric(float dis_order);
//nodes initiation
//hybrid
int	is_in_range(int val, int min, int max);
int	get_hybrid_chunk_size(int size);
void	hybrid_push_range (s_node **a,s_node **b, int min, int max, s_flags *flags);
void	hybrid_push_all_ranges(s_node **a, s_node **b, s_flags *flags);
int	find_max_index(s_node *b);
int	get_distance_to_top(s_node *s, int val);
void	hybrid_push_back(s_node **a, s_node **b, s_flags *flags);
void	hybrid_chunk_sort(s_node **a, s_node **b, s_flags *flags);
//index 
void	fill_values_array(s_node *stack, int *arr);
int	compute_index(int *arr, int total, int value);
void	assign_indices(s_node *stack, int *arr, int total);
//medium_sort
int in_chunk (int val, int min, int max);
int	find_max(s_node *stack_a);
int distance_to_top(s_node *stack_a, int val);
int distance_to_bottom(s_node *stack, int val);
s_node *find_next_in_chunk(s_node *stack, int min, int max);
void	push_chunk(s_node **stack_a, s_node **stack_b, int min, int max, s_flags *flags);
void	push_back_max(s_node **stack_a, s_node **stack_b, s_flags *flags);
void	chunk_sort(s_node **stack_a, s_node **stack_b, s_flags *flags);
//complex_sort
void stack_index(s_node *stack_a);
int bits_max(s_node *stack_a);
void bit_process(s_node **stack_a, s_node **stack_b,s_flags *flags, int bits);
void complex_sort(s_node **stack_a, s_node **stack_b, s_flags *flags);
//stack utils
void bit_process(s_node **stack_a, s_node **stack_b,s_flags *flags, int bits);
void free_stack(s_node **stack);
//simple
int *stack_to_intarr(s_node *stack_a);
void simple_sort(s_node *stack_a, s_flags *flags);
//flags
void read_flags(int *ac, char ***av, s_flags *flags);
int check_flag(char *av, s_flags *flags);
void rem_flags(int *ac, char ***av, int index);
int	ft_strcmp(char *s1, char *s2);
void print_bench(s_flags *flags, float disorder);
//commands
void swap(s_node *head);
void sa(s_node *stack_a, s_flags *flags);
void sb(s_node *stack_b, s_flags *flags);
void ss(s_node *stack_a, s_node *stack_b, s_flags *flags);
void push(s_node **stack_a, s_node **stack_b);
void pa(s_node **stack_a, s_node **stack_b, s_flags *flags);
void pb(s_node **stack_b, s_node **stack_a, s_flags *flags);
void rotate(s_node **head);
void ra(s_node **stack_a, s_flags *flags);
void rb(s_node **stack_b, s_flags *flags);
void rr(s_node **stack_a, s_node **stack_b, s_flags *flags);
void reverse_rotate(s_node **head);
void rra(s_node **stack_a, s_flags *flags);
void rrb(s_node **stack_b, s_flags *flags);
void rrr(s_node **stack_a, s_node **stack_b, s_flags *flags);
//algorithms

#endif