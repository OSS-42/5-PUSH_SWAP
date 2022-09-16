/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_utils_b_to_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:51:15 by ewurstei          #+#    #+#             */
/*   Updated: 2022/09/15 16:26:42 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves_cost_max_in_b(t_vault *data)
{
	is_min_a(data);
	is_max_b(data);
	check_qty_stack_a(data);
	if (data->is_in_order_a == 1)
		data->cost_a_to_top = 0;
	else if (data->min_a_pos <= (data->index_max - (data->qty_stack_a / 2) - 1))
		data->cost_a_to_top = data->min_a_pos
			- ((data->index_max - 1) - (data->qty_stack_a - 1));
	else
		data->cost_a_to_top = data->min_a_pos - (data->index_max - 1);
	check_qty_stack_b(data);
	check_reverse_order_b(data);
	if (data->is_in_order_b == -2)
		data->cost_b_to_top = 0;
	else if (data->max_b_pos <= (data->index_max - (data->qty_stack_b / 2) - 1))
		data->cost_b_to_top = data->max_b_pos
			- ((data->index_max - 1) - (data->qty_stack_b - 1));
	else
		data->cost_b_to_top = data->max_b_pos - (data->index_max);
}

void	moves_cost_max_in_a(t_vault *data)
{
	check_qty_stack_a(data);
	check_order_a(data);
	is_min_a(data);
	is_max_b(data);
	if (data->is_in_order_a == 1 && data->is_min_a > data->is_max_b)
		data->cost_a_to_top = 0;
	else if (data->is_min_a + 1 == data->is_max_b)
		data->cost_a_to_top = 1;
	else if (data->min_a_pos <= (data->index_max - (data->qty_stack_a / 2) - 1))
		data->cost_a_to_top = data->min_a_pos
			- ((data->index_max - 1) - (data->qty_stack_a - 1));
	else if (data->min_a_pos == data->index_max - 1)
		data->cost_a_to_top = -1;
	else
		data->cost_a_to_top = data->min_a_pos - (data->index_max - 1);
	check_qty_stack_b(data);
	check_reverse_order_b(data);
	if (data->is_in_order_b == -2)
		data->cost_b_to_top = 0;
	else if (data->max_b_pos <= (data->index_max - (data->qty_stack_b / 2) - 1))
		data->cost_b_to_top = data->max_b_pos
			- ((data->index_max - 1) - (data->qty_stack_b - 1));
	else
		data->cost_b_to_top = data->max_b_pos - (data->index_max);
}

void	smart_sort_a(t_vault *data, unsigned int x,
			unsigned int y, unsigned int z)
{
	if (data->stack_b[y] == data->index_max)
	{
		push_to_a(data);
		rotate_to_last_a(data);
	}
	else if (data->stack_a[x] < data->stack_b[y]
		&& data->stack_a[x + 1] < data->stack_b[y])
	{
		rotate_to_last_a(data);
		z++;
	}
	else if (data->stack_a[x] < data->stack_b[y]
		&& data->stack_a[x + 1] > data->stack_b[y])
	{
		rotate_to_last_a(data);
		push_to_a(data);
		z++;
	}
	else
		moves_cost_max_in_b(data);
}

void	check_before_max_b(t_vault *data)
{
	unsigned int	x;

	x = position_x_b(data);
	is_max_b(data);
	if (data->stack_b[x] == data->is_max_b - 1)
		push_to_a(data);
	moves_cost_max_in_b(data);
}

void	moves_b_to_a(t_vault *data)
{
	if (data->cost_a_to_top > 0 && data->cost_b_to_top > 0)
	{
		rotate_both_to_last(data);
		check_before_max_b(data);
	}
	else if (data->cost_a_to_top < 0 && data->cost_b_to_top < 0)
	{
		rotate_both_to_first(data);
		check_before_max_b(data);
	}
	else if (data->cost_a_to_top < 0 && data->cost_b_to_top == 0)
		rotate_to_first_a(data);
	else if (data->cost_b_to_top > 0 && data->cost_a_to_top == 0)
	{
		rotate_to_last_b(data);
		check_before_max_b(data);
	}
	else if (data->cost_a_to_top > 0 && data->cost_b_to_top == 0)
		rotate_to_last_a(data);
	else
	{
		rotate_to_first_b(data);
		check_before_max_b(data);
	}
}

/*
void	preparation_of_a(t_vault *data, unsigned int x, unsigned int y)
{
	unsigned int	z;

	is_min_a(data);
	is_max_b(data);
	z = 0;
	while (data->is_min_a < data->is_max_b)
	{
		x = position_x_a(data);
		y = 0;
		while (data->stack_b[y] == 0)
			y++;
		smart_sort_a(data, x, y, z);
		while (z > 0 && data->stack_a[x] > data->stack_b[y])
		{
			if (data->stack_a[x - 1] == data->stack_b[y])
				push_to_a(data);
			rotate_to_first_a(data);
			z--;
		}
		is_min_a(data);
		is_max_b(data);
	}
}
*/