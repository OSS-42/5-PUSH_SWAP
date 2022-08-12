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
	while (data->stack_b[x] == 0)
		x++;
	while (x < data->index)
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
	while (data->stack_a[x] == 0)
		x++;
	while (x < data->index)
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
	if (data->qty_stack_a == 1 || data->qty_stack_a == 0)
		return ;
	else
	{
		while (data->stack_a[x] != 0)
			x++;
		data->nbr_temp = data->stack_a[x];
		data->stack_a[x] = data->stack_a[x + 1];
		data->stack_a[x + 1] = data->nbr_temp;
		printf("%s\n", "sa");
	}
}

void	swap_top_b(t_vault *data)
{
	unsigned int	x;

	x = 0;
	check_qty_stack_b(data);
	if (data->qty_stack_b == 1 || data->qty_stack_b == 0)
		return ;
	else
	{
		while (data->stack_b[x] != 0)
			x++;
		data->nbr_temp = data->stack_b[x];
		data->stack_b[x] = data->stack_b[x + 1];
		data->stack_b[x + 1] = data->nbr_temp;
		printf("%s\n", "sb");
	}
}

void	both_swap_top(t_vault *data)
{
	unsigned int	x;

	x = 0;
	check_qty_stack_a(data);
	if (data->qty_stack_a > 1)
	{
		while (data->stack_a[x] != 0)
			x++;
		data->nbr_temp = data->stack_a[x];
		data->stack_a[x] = data->stack_a[x + 1];
		data->stack_a[x + 1] = data->nbr_temp;
	}
	else if (data->qty_stack_b > 1)
	{
		x = 0;
		while (data->stack_b[x] != 0)
			x++;
		data->nbr_temp = data->stack_b[x];
		data->stack_b[x] = data->stack_b[x + 1];
		data->stack_b[x + 1] = data->nbr_temp;
	}
	else
		return ;
	printf("%s\n", "ss");
}
