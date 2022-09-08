/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:39:08 by ewurstei          #+#    #+#             */
/*   Updated: 2022/09/07 21:39:08 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_order_b(t_vault *data)
{
	unsigned int	x;

	x = 0;
	while (data->stack_b[x] == 0)
		x++;
	while (x < data->index_max - 1)
	{
		if (data->stack_b[x] > data->stack_b[x + 1])
		{
			data->is_in_order_b = -1;
			return ;
		}
		else
			x++;
	}
	data->is_in_order_b = 1;
	return ;
}

void	check_order_a(t_vault *data)
{
	unsigned int	x;

	x = 0;
	while (data->stack_a[x] == 0)
		x++;
	while (x < data->index_max - 1)
	{
		if (data->stack_a[x] > data->stack_a[x + 1])
		{
			data->is_in_order_a = -1;
			return ;
		}
		else
			x++;
	}
	data->is_in_order_a = 1;
	return ;
}

void	check_reverse_order_b(t_vault *data)
{
	unsigned int	x;

	x = 0;
	data->is_in_order_b = 0;
	while (data->stack_b[x] == 0)
		x++;
	while (x < data->index_max - 1)
	{
		if (data->stack_b[x + 1] > data->stack_b[x])
		{
			data->is_in_order_a = -1;
			return ;
		}
		else
			x++;
	}
	data->is_in_order_b = -2;
	return ;
}
