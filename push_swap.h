/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:17:23 by cschwart          #+#    #+#             */
/*   Updated: 2026/01/17 19:02:22 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "stderr_printf/stderr_printf.h"

typedef struct s_node
{
	int				nb;
	int				index;
	int				cost;
	int				plus_med;
	int				closest;
	bool			av_err;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_chunk
{
	int	min;
	int	max;
}	t_chunk;

typedef struct s_min
{
	t_node	*min;
	int		pos;
	int		size;
}			t_min;

typedef struct s_flags
{
	int		total;
	int		bench;
	int		algo;
	int		algo_set;
	float	disorder;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_flags;

void	insert_af(t_node **stack, int nb);
void	free_stack(t_node **stack_a, t_node **stack_b);
void	free_char(char **av);
long	ft_atol(const char *nptr);
void	init_main_stack(int ac, char **av, t_node **stack_a,
			t_flags *flags);

// sorting
void	sort(t_node **stack_a, t_node **stack_b, t_flags *flags);
//turk
void	rev_rot_rrr(t_node **stack_a, t_node **stack_b, t_node *minst_val,
			t_flags *flags);
void	rotate_rr(t_node **stack_a, t_node **stack_b, t_node *minst_node,
			t_flags *flags);
void	sort_three(t_node **stack_a, t_flags *flags);
void	push_and_sort_a(t_node **stack_a, t_node **stack_b, t_flags *flags);
void	turk_sort(t_node **stack_a, t_node **stack_b, t_flags *flags);
void	update_index(t_node *stack);
t_node	*find_max_node(t_node *stack);
void	fill_nodes_a(t_node *stack_a, t_node *stack_b);
void	aim_node_a(t_node *stack_a, t_node *stack_b);
void	while_cur_b(t_node *stack_a, t_node *stack_b);
void	calc_cost(t_node *stack_a, t_node *stack_b);
void	closest_set(t_node *stack);
void	fill_nodes_b(t_node *stack_a, t_node *stack_b);
void	aim_node_b(t_node *stack_a, t_node *stack_b);
void	calc_cost_b(t_node *stack_a, t_node *stack_b);
void	final_sort(t_node **stack_a, t_flags *flags);
void	transfer_to_b(t_node **stack_a, t_node **stack_b, t_flags *flags);
void	transfer_to_a(t_node **stack_a, t_node **stack_b, t_flags *flags);
t_node	*find_closest(t_node *stack);
void	pre_push(t_node **stack, t_node *node_top, t_flags *flags,
			char stack_name);
t_node	*find_minimum(t_node *stack);
int		node_cost(t_node *n, int len);
int		merge_cost(t_node *src, t_node *dst, int cost_s, int cost_d);
//handle error
int		err_dup(t_node *stack_a, int value);
int		err_over_flow(char *av);
int		err_inval_char(char *av);
void	show_err(int x, char **av, t_node *stack_a, bool test);
void	check_input(t_node *stack_a, char *av, char **argv, bool test);
//stack initiation
int		ft_sorted(t_node *stack_a);
int		len_stack(t_node *stack_a);
long	ft_atol(const char *nptr);
float	compute_disorder(t_node *stack_a, t_flags *flags);
void	disorder_metric(float dis_order);
//nodes initiation

//index 
void	fill_values_array(t_node *stack, int *arr);
int		compute_index(int *arr, int total, int value);
void	assign_indices(t_node *stack, int *arr, int total);
//medium_sort
int		in_chunk(int val, int min, int max);
int		find_max(t_node *stack_a);
int		distance_to_top(t_node *stack_a, int val);
int		distance_to_bottom(t_node *stack, int val);
t_node	*find_next_in_chunk(t_node *stack, int min, int max);
void	move_target_to_top(t_node **stack_a, t_node *target,
			t_flags *flags);
void	push_chunk(t_node **stack_a, t_node **stack_b,
			t_chunk chunk, t_flags *flags);
void	push_back_max(t_node **stack_a, t_node **stack_b, t_flags *flags);
void	chunk_sort(t_node **stack_a, t_node **stack_b, t_flags *flags);
//complex_sort
void	stack_index(t_node *stack_a);
int		bits_max(t_node *stack_a);
void	bit_process(t_node **stack_a, t_node **stack_b, t_flags *flags,
			int bits);
void	complex_sort(t_node **stack_a, t_node **stack_b, t_flags *flags);
//stack utils
void	bit_process(t_node **stack_a, t_node **stack_b, t_flags *flags,
			int bits);
//simple
int		*stack_to_intarr(t_node *stack_a);
void	simple_sort(t_node **stack_a, t_node **stack_b, t_flags *flags);
t_min	get_min(t_node *stack);
void	pb_rb(t_node **stack_a, t_node **stack_b, t_flags *flags);
void	simple_transfer_to_b(t_node **stack_a, t_node **stack_b,
			t_flags *flags);
//flags
void	read_flags(int *ac, char ***av, t_flags *flags);
int		check_flag(char *av, t_flags *flags);
void	rem_flags(int *ac, char ***av, int index);
int		ft_strcmp(char *s1, char *s2);
void	print_bench(t_flags *flags, float disorder);
//commands
void	swap(t_node *head);
void	sa(t_node *stack_a, t_flags *flags);
void	sb(t_node *stack_b, t_flags *flags);
void	ss(t_node *stack_a, t_node *stack_b, t_flags *flags);
void	push(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b, t_flags *flags);
void	pb(t_node **stack_b, t_node **stack_a, t_flags *flags);
void	push_a(t_node **stack_a, t_node **stack_b, t_flags *flags);
void	push_b(t_node **stack_a, t_node **stack_b, t_flags *flags);
void	rotate(t_node **head);
void	ra(t_node **stack_a, t_flags *flags);
void	rb(t_node **stack_b, t_flags *flags);
void	rr(t_node **stack_a, t_node **stack_b, t_flags *flags);
void	reverse_rotate(t_node **head);
void	rra(t_node **stack_a, t_flags *flags);
void	rrb(t_node **stack_b, t_flags *flags);
void	rrr(t_node **stack_a, t_node **stack_b, t_flags *flags);
//algorithms

#endif
