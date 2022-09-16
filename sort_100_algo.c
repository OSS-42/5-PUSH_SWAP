/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:32:46 by ewurstei          #+#    #+#             */
/*   Updated: 2022/09/16 13:38:56 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_100_loop_a(t_vault *data, unsigned int div)
{
	unsigned int	x;
	unsigned int	y;

	while (data->round > 0 && data->qty_stack_a > 3)
	{
		x = position_x_a(data);
		if (data->stack_a[x] > div
			&& data->stack_a[x] <= data->index_max - div
			&& data->stack_a[x] <= data->index_max - 3)
		{
			push_to_b(data);
			y = position_x_b(data);
			if (data->stack_b[y] <= data->index_max / 2)
				rotate_to_last_b(data);
			else if (data->stack_b[y] < data->stack_b[y + 1])
				swap_top_b(data);
		}
		else
			rotate_to_last_a(data);
		data->round--;
		check_qty_stack_a(data);
	}
}

void	sort_100_a_to_b(t_vault *data)
{
	unsigned int	div;

	check_qty_stack_a(data);
	div = data->qty_stack_a / 4;
	while (data->qty_stack_a > 3)
	{
		data->round = data->qty_stack_a;
		sort_100_loop_a(data, div);
		check_qty_stack_a(data);
		div /= 2;
	}
	sort_3_init(data);
}

void	sort_100_b_to_a(t_vault *data)
{
	unsigned int	x;

	check_qty_stack_b(data);
	while (data->qty_stack_b > 0)
	{
		moves_cost_max_in_a(data);
		check_before_max_b(data);
		while (abs(data->cost_a_to_top) + abs(data->cost_b_to_top) != 0)
			moves_b_to_a(data);
		push_to_a(data);
		is_min_a(data);
		x = position_x_a(data);
		if (data->stack_a[x] == data->is_min_a + 1)
			swap_top_a(data);
		check_qty_stack_b(data);
	}
}

void	sort_100(t_vault *data)
{
	sort_100_a_to_b(data);
	sort_100_b_to_a(data);
	check_order_a(data);
	if (data->is_in_order_a == 1 && data->moves > 0)
		return ;
}

/*
void	sort_100_a_to_b(t_vault *data)
{
	unsigned int	y;
	unsigned int	x;

	check_qty_stack_a(data);
	check_qty_stack_b(data);
	y = 1;
	while (y <= data->pivot_round)
	{
		while (data->qty_stack_b < data->pivot * y && data->qty_stack_a > 3)
		{
			x = position_x_a(data);
			determine_next_move_in_a(data, y);
			if (data->stack_a[x] <= data->pivot * y
				|| data->stack_a[x] != data->index_max
				|| data->stack_a[x] != data->index_max - 1
				|| data->stack_a[x] != data->index_max - 2)
				push_to_b(data);
			smart_sort_b(data);
			check_qty_stack_a(data);
			check_qty_stack_b(data);
		}
		y++;
	}
}
*/

/*
void	sort_100_clean_a(t_vault *data)
{
	unsigned int	x;

	check_qty_stack_a(data);
	while (data->qty_stack_a > 3)
	{
		x = position_x_a(data);
		if (data->stack_a[x] != data->index_max
			&& data->stack_a[x] != data->index_max - 1
			&& data->stack_a[x] != data->index_max - 2)
			push_to_b(data);
		else
			rotate_to_last_a(data);
		check_qty_stack_a(data);
	}
	sort_3_init(data);
}
*/
