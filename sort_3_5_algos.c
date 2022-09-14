/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:30:17 by ewurstei          #+#    #+#             */
/*   Updated: 2022/09/12 16:23:52 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_loop(t_vault *data, unsigned int x)
{
	if (data->qty_stack_a == 2)
		rotate_to_last_a(data);
	else if (data->stack_a[x] == data->is_min_a)
	{
		swap_top_a(data);
		rotate_to_last_a(data);
	}
	else if (data->stack_a[x] == data->is_max_a)
	{
		if (data->stack_a[x + 1] == data->is_min_a)
			rotate_to_last_a(data);
		else
		{
			rotate_to_last_a(data);
			swap_top_a(data);
		}
	}
	else
	{
		if (data->stack_a[x + 1] == data->is_min_a)
			swap_top_a(data);
		else
			rotate_to_first_a(data);
	}
	return ;
}

void	sort_3_init(t_vault *data)
{
	unsigned int	x;

	check_qty_stack_a(data);
	check_order_a(data);
	if (data->is_in_order_a == 1)
		return ;
	x = position_x_a(data);
	is_min_a(data);
	is_max_a(data);
	sort_3_loop(data, x);
	check_order_a(data);
	return ;
}

void	sort_5_part2(t_vault *data, unsigned int x)
{
	check_qty_stack_b(data);
	check_reverse_order_b(data);
	if (data->is_in_order_b != -2)
		rotate_to_last_b(data);
	while (data->qty_stack_b > 0)
	{
		push_to_a(data);
		x = position_x_a(data);
		if (data->stack_a[x] > data->stack_a[x + 1])
			swap_top_a(data);
		check_qty_stack_b(data);
		check_order_a(data);
		if (data->moves > 0 && data->is_in_order_a == 1
			&& data->qty_stack_b == 0)
			return ;
	}
	return ;
}

void	sort_5(t_vault *data)
{
	unsigned int	x;

	check_qty_stack_a(data);
	while (data->qty_stack_a > 3)
	{
		x = position_x_a(data);
		check_order_a(data);
		if (data->is_in_order_a == 1 && data->qty_stack_a == data->index_max)
			break ;
		if (data->stack_a[x] > data->qty_stack_a / 2 + x)
			rotate_to_last_a(data);
		else if (data->stack_a[x] <= data->qty_stack_a / 2 + x)
			push_to_b(data);
		check_qty_stack_a(data);
	}
	if (data->is_in_order_a == 1 && data->qty_stack_a == data->index_max)
		return ;
	sort_3_init(data);
	sort_5_part2(data, x);
	return ;
}
