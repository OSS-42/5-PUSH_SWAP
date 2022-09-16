/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_utils_a_to_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:58:04 by ewurstei          #+#    #+#             */
/*   Updated: 2022/09/16 10:14:47 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	determine_pivot(t_vault *data)
{
	check_order_a(data);
	if (data->is_in_order_a == 1)
		return ;
	if (data->index_max <= 20)
	{
		data->pivot = data->index_max / 2;
		data->pivot_round = 2;
	}
	if (data->index_max > 20 && data->index_max <= 100)
	{
		data->pivot = data->index_max / 4;
		data->pivot_round = 4;
	}
	if (data->index_max > 100)
	{
		data->pivot = data->index_max / 10;
		data->pivot_round = 10;
	}
}
*/

void	next_move_stack_a(t_vault *data, unsigned int y)
{
	unsigned int	x;

	x = position_x_a(data);
	data->next_nbr_ra = 0;
	while (data->stack_a[x] > data->pivot * y
		|| data->stack_a[x] == data->index_max
		|| data->stack_a[x] == data->index_max - 1
		|| data->stack_a[x] == data->index_max - 2)
	{
		x++;
		data->next_nbr_ra++;
	}
	x = data->index_max - 1;
	data->next_nbr_rra = 1;
	while (data->stack_a[x] >= data->pivot * y
		|| data->stack_a[x] == data->index_max
		|| data->stack_a[x] == data->index_max - 1
		|| data->stack_a[x] == data->index_max - 2)
	{
		x--;
		data->next_nbr_rra++;
	}
}

void	determine_next_move_in_a(t_vault *data, unsigned int y)
{
	next_move_stack_a(data, y);
	if (data->next_nbr_ra < data->next_nbr_rra
		|| data->next_nbr_ra == data->next_nbr_rra)
	{
		while (data->next_nbr_ra > 0)
		{
			rotate_to_last_a(data);
			data->next_nbr_ra--;
		}
	}
	else if (data->next_nbr_ra > data->next_nbr_rra)
	{
		while (data->next_nbr_rra > 0)
		{
			rotate_to_first_a(data);
			data->next_nbr_rra--;
		}
	}
}

void	smart_sort_b(t_vault *data)
{
	unsigned int	x;

	x = 0;
	check_qty_stack_b(data);
	while (data->stack_b[x] == 0)
		x++;
	if ((data->stack_b[x] < data->qty_stack_b / 3
			&& data->stack_b[x] < data->stack_b[x + 1])
		|| data->stack_b[x] == 1)
		rotate_to_last_b(data);
	else if (data->stack_b[x] < data->stack_b[x + 1])
		swap_top_b(data);
}
