/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:32:43 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/10 14:55:25 by ewurstei         ###   ########.fr       */
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
	unsigned int	position;
	long			min;
	unsigned int	*stack_a;
	unsigned int	nbr_args;
}	t_vault;

/*****Fonctions*****/

void	errors(t_vault *data);
void	indexing_numbers(t_vault *data);

#endif
