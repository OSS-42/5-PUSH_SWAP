/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:25:03 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/11 13:11:23 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_qty_stack_b(t_vault *data)
{
	unsigned int	x;

	x = 0;
	data->qty_stack_b = 0;
	while (data->stack_b[x] == 0 && x < data->index_max)
		x++;
	while (x < data->index_max)
	{
		data->qty_stack_b++;
		x++;
	}
}

void	check_qty_stack_a(t_vault *data)
{
	unsigned int	x;

	x = 0;
	data->qty_stack_a = 0;
	while (data->stack_a[x] == 0 && x < data->index_max)
		x++;
	while (x < data->index_max)
	{
		data->qty_stack_a++;
		x++;
	}
}

void	swap_top_a(t_vault *data)
{
	unsigned int	x;

	x = 0;
	check_qty_stack_a(data);
	if (data->qty_stack_a <= 1)
		return ;
	else
	{
		while (data->stack_a[x] == 0)
			x++;
		data->nbr_temp = data->stack_a[x];
		data->stack_a[x] = data->stack_a[x + 1];
		data->stack_a[x + 1] = data->nbr_temp;
		data->moves++;
		printf("%s\n", "sa");
	}
}

void	swap_top_b(t_vault *data)
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
		data->nbr_temp = data->stack_b[x];
		data->stack_b[x] = data->stack_b[x + 1];
		data->stack_b[x + 1] = data->nbr_temp;
		data->moves++;
		printf("%s\n", "sb");
	}
}

void	swap_both_top(t_vault *data)
{
	unsigned int	x;

	x = 0;
	check_qty_stack_a(data);
	check_qty_stack_b(data);
	if (data->qty_stack_a > 1)
	{
		while (data->stack_a[x] == 0)
			x++;
		data->nbr_temp = data->stack_a[x];
		data->stack_a[x] = data->stack_a[x + 1];
		data->stack_a[x + 1] = data->nbr_temp;
	}
	else if (data->qty_stack_b > 1)
	{
		x = 0;
		while (data->stack_b[x] == 0)
			x++;
		data->nbr_temp = data->stack_b[x];
		data->stack_b[x] = data->stack_b[x + 1];
		data->stack_b[x + 1] = data->nbr_temp;
	}
	else
		return ;
	data->moves++;
	printf("%s\n", "ss");
}
