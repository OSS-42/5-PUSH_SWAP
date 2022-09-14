/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:23:19 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/11 13:13:03 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Attention au data->index (commence à 1) et aux positions d'array : 
data->index_max
*/

void	rotate_to_last_a(t_vault *data)
{
	unsigned int	x;

	check_qty_stack_a(data);
	if (data->qty_stack_a <= 1)
		return ;
	else
	{
		x = position_x_a(data);
		while (x < data->index_max - 1 && data->stack_a[x] != 0)
		{
			data->nbr_temp = data->stack_a[x];
			data->stack_a[x] = data->stack_a[x + 1];
			data->stack_a[x + 1] = data->nbr_temp;
			x++;
		}
		data->moves++;
		if (data->is_it_both != 1)
			printf("%s\n", "ra");
	}
	return ;
}

void	rotate_to_first_a(t_vault *data)
{
	unsigned int	x;

	x = data->index_max - 1;
	check_qty_stack_a(data);
	if (data->qty_stack_a <= 1)
		return ;
	else
	{
		while (x > 0 && data->stack_a[x - 1] != 0)
		{
			data->nbr_temp = data->stack_a[x];
			data->stack_a[x] = data->stack_a[x - 1];
			data->stack_a[x - 1] = data->nbr_temp;
			x--;
		}
		data->moves++;
		if (data->is_it_both != 1)
			printf("%s\n", "rra");
	}
}

void	rotate_to_last_b(t_vault *data)
{
	unsigned int	x;

	x = 0;
	check_qty_stack_b(data);
	if (data->qty_stack_b <= 1)
		return ;
	else
	{
		while (data->stack_b[x] == 0)
			x++;
		while (x < data->index_max - 1 && data->stack_b[x] != 0)
		{
			data->nbr_temp = data->stack_b[x];
			data->stack_b[x] = data->stack_b[x + 1];
			data->stack_b[x + 1] = data->nbr_temp;
			x++;
		}
		data->moves++;
		if (data->is_it_both != 1)
			printf("%s\n", "rb");
	}
}

void	rotate_to_first_b(t_vault *data)
{
	unsigned int	x;

	x = data->index_max - 1;
	check_qty_stack_b(data);
	if (data->qty_stack_b <= 1)
		return ;
	else
	{
		while (x > 0 && data->stack_b[x - 1] != 0)
		{
			data->nbr_temp = data->stack_b[x];
			data->stack_b[x] = data->stack_b[x - 1];
			data->stack_b[x - 1] = data->nbr_temp;
			x--;
		}
		data->moves++;
		if (data->is_it_both != 1)
			printf("%s\n", "rrb");
	}
}
