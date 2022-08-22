/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:32:43 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/11 14:55:43 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "includes/libft/libft.h"

/*****Node*****/

/*typedef struct s_node
{
	char			*move;
	struct s_node	*next;
}	t_node;
*/
/*****Data*****/

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
	unsigned int	is_min_b;
	unsigned int	is_max_a;
	unsigned int	is_max_b;	
	unsigned int	moves;
	t_list			**moves_list;
	unsigned int	ind_moves_list;
	unsigned int	difficulty;
}	t_vault;

/*****Fonctions*****/

void	errors(t_vault *data);
void	indexing_numbers(t_vault *data);
void	algo_choice(t_vault *data);
void	push_to_a(t_vault *data);
void	push_to_b(t_vault *data);
void	rotate_to_last_b(t_vault *data);
void	rotate_to_first_a(t_vault *data);
void	rotate_to_first_b(t_vault *data);
void	rotate_to_last_a(t_vault *data);
void	swap_top_a(t_vault *data);
void	swap_top_b(t_vault *data);
void	both_swap_top(t_vault *data);
void	both_rotate_to_first(t_vault *data);
void	both_rotate_to_last(t_vault *data);
void	check_qty_stack_a(t_vault *data);
void	check_qty_stack_b(t_vault *data);
void	stacks_visu(t_vault *data); //pour debug
void	check_index(t_vault *data); //pour debug
void	check_order_a(t_vault *data);
void	check_order_b(t_vault *data);
void	is_min_a(t_vault *data);
void	is_max_a(t_vault *data);
void	is_min_b(t_vault *data);
void	is_max_b(t_vault *data);
void	check_difficulty(t_vault *data); // pas utilisé
//void	add_to_moves_list(t_vault *data, char *move_name); // pas utilisé
void	sort_3_a(t_vault *data);
void	sort_3_b(t_vault *data);
void	sort_4_a(t_vault *data);
void	sort_5(t_vault *data);

#endif
