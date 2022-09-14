/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:33:55 by ewurstei          #+#    #+#             */
/*   Updated: 2022/09/14 11:33:55 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_500_bits(t_vault *data, unsigned int round)
{
	unsigned int	value;
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < data->index_max)
	{
		x = position_x_a(data);
		value = data->stack_a[x] >> round;
		if ((value & 1) == 1)
		{
			rotate_to_last_a(data);
			check_order_a(data);
		}
		else if (data->is_in_order_a != 1)
			push_to_b(data);
		y++;
	}
}

void	sort_500(t_vault *data)
{
	unsigned int	round;

	round = 0;
	data->max_bits = 0;
	while (((data->index_max - 1) >> data->max_bits) != 0)
		data->max_bits++;
	while (round < data->max_bits)
	{
		sort_500_bits(data, round);
		check_qty_stack_b(data);
		while (data->qty_stack_b > 0)
		{
			push_to_a(data);
			check_qty_stack_b(data);
		}
		round++;
	}
}
