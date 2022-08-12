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

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
}	t_node;

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
}	t_vault;

/*****Fonctions*****/

void	errors(t_vault *data);
void	indexing_numbers(t_vault *data);
void	sorting_numbers(t_vault *data);
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
void	small_sorting(t_vault *data);

#endif
