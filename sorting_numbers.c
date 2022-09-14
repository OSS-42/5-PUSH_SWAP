/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:03:54 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/11 15:49:12 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_min_a(t_vault *data)
{
	unsigned int	x;

	x = 0;
	while (data->stack_a[x] == 0)
		x++;
	data->is_min_a = data->stack_a[x];
	data->min_a_pos = x;
	x++;
	while (x < data->index_max)
	{
		if (data->stack_a[x] < data->is_min_a)
		{
			data->is_min_a = data->stack_a[x];
			data->min_a_pos = x;
		}
		else
			x++;
	}
	return ;
}

void	is_max_a(t_vault *data)
{
	unsigned int	x;

	x = 0;
	while (data->stack_a[x] == 0)
		x++;
	data->is_max_a = data->stack_a[x];
	x++;
	while (x < data->index_max)
	{
		if (data->stack_a[x] > data->is_max_a)
			data->is_max_a = data->stack_a[x];
		else
			x++;
	}
	return ;
}

void	is_min_b(t_vault *data)
{
	unsigned int	x;

	x = 0;
	while (data->stack_b[x] == 0)
		x++;
	data->is_min_b = data->stack_b[x];
	x++;
	while (x < data->index_max)
	{
		if (data->stack_b[x] < data->is_min_b)
			data->is_min_b = data->stack_b[x];
		else
		x++;
	}
	return ;
}

void	is_max_b(t_vault *data)
{
	unsigned int	x;

	x = 0;
	while (data->stack_b[x] == 0)
		x++;
	data->is_max_b = data->stack_b[x];
	data->max_b_pos = x;
	x++;
	while (x < data->index_max)
	{
		if (data->stack_b[x] > data->is_max_b)
		{
			data->is_max_b = data->stack_b[x];
			data->max_b_pos = x;
		}
		else
			x++;
	}
	return ;
}

void	next_move_stack_a(t_vault *data, unsigned int y)
{
	unsigned int	x;

	x = 0;
	while (data->stack_a[x] == 0)
		x++;
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