/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:32:43 by ewurstei          #+#    #+#             */
/*   Updated: 2022/09/12 15:39:05 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "includes/libft/libft.h"

typedef struct s_vault
{
	int				error_code;
	char			**args;
	long			*args_int;
	unsigned int	*switches;
	unsigned int	index;
	unsigned int	index_max;
	unsigned int	position;
	long			min;
	unsigned int	*stack_a;
	unsigned int	qty_stack_a;
	unsigned int	*stack_b;
	unsigned int	qty_stack_b;
	unsigned int	nbr_temp;
	unsigned int	nbr_args;
	int				is_in_order_a;
	int				is_in_order_b;
	unsigned int	is_min_a;
	unsigned int	min_a_pos;
	unsigned int	is_max_a;
	unsigned int	is_min_b;
	unsigned int	is_max_b;
	unsigned int	max_b_pos;
	unsigned int	pivot;
	unsigned int	pivot_round;
	unsigned int	max_bits;
	unsigned int	round;
	unsigned int	value;
	unsigned int	next_nbr_ra;
	unsigned int	next_nbr_rra;
	int				cost_a_to_top;
	int				cost_b_to_top;
	unsigned int	moves;
	int				is_it_both;
}	t_vault;

/***** Parsing & logique *****/
void			from_a_to_long(t_vault *data);
void			check_doubles(t_vault *data);
int				check_args(t_vault *data);
int				quotes_to_args(t_vault *data, char **argv);
void			saving_args(t_vault *data, int argc, char **argv);
void			struct_init(t_vault *data);
void			errors(t_vault *data);
void			indexing_numbers(t_vault *data);
void			indexing_loop(t_vault *data);
void			algo_choice(t_vault *data);

/***** Common utils *****/
void			check_qty_stack_a(t_vault *data);
void			check_qty_stack_b(t_vault *data);
void			check_order_a(t_vault *data);
void			check_reverse_order_b(t_vault *data);
void			check_order_b(t_vault *data);
void			is_min_a(t_vault *data);
void			is_max_a(t_vault *data);
void			is_min_b(t_vault *data);
void			is_max_b(t_vault *data);
unsigned int	position_x_a(t_vault *data);

/***** push_swap moves *****/
void			push_to_a(t_vault *data);
void			push_to_b(t_vault *data);
void			rotate_to_last_b(t_vault *data);
void			rotate_to_first_a(t_vault *data);
void			rotate_to_first_b(t_vault *data);
void			rotate_to_last_a(t_vault *data);
void			swap_top_a(t_vault *data);
void			swap_top_b(t_vault *data);
void			swap_both_top(t_vault *data);
void			rotate_both_to_first(t_vault *data);
void			rotate_both_to_last(t_vault *data);

/***** sorting algos *****/
void			sort_3_init(t_vault *data);
void			sort_5(t_vault *data);
void			sort_5_part2(t_vault *data, unsigned int x);
void			sort_100(t_vault *data);
void			sort_100_a_to_b(t_vault *data);
void			sort_100_clean_a(t_vault *data);
void			sort_100_b_t_a(t_vault *data);
void			sort_500(t_vault *data);
void			sort_500_bits(t_vault *data, unsigned int round);

/***** sort_100_utils *****/
/***** A to B *****/
void			next_move_stack_a(t_vault *data, unsigned int y);
void			determine_next_move_in_a(t_vault *data, unsigned int y);
void			smart_sort_b(t_vault *data);
void			determine_pivot(t_vault *data);
/***** B to A *****/
void			moves_cost_max_in_b(t_vault *data);
void			moves_cost_max_in_a(t_vault *data);
void			smart_sort_a(t_vault *data, unsigned int x,
					unsigned int y, unsigned int z);
void			preparation_of_a(t_vault *data, unsigned int x, unsigned int y);
void			moves_b_to_a(t_vault *data);

/***** Pour debug *****/
//void	stacks_visu(t_vault *data); //pour debug
//void	check_index(t_vault *data); //pour debug

#endif
