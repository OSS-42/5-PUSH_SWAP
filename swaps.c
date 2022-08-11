/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:25:03 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/10 22:25:03 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_qty_stack_b(t_vault *data)
{
	unsigned int	x;

	if (!data->stack_b[0])
		return (1);
	data->qty_stack_b = 1;
	x = 0;
	while (data->stack_b[x])
	{
		data->qty_stack_b++;
		x++;
	}
	if (data->qty_stack_b == 1)
		return (1);
	else
		return (0);
}

int	check_qty_stack_a(t_vault *data)
{
	unsigned int	x;

	if (!data->stack_a[0])
		return (1);
	data->qty_stack_a = 1;
	x = 0;
	while (data->stack_a[x])
	{
		data->qty_stack_a++;
		x++;
	}
	if (data->qty_stack_a == 1)
		return (1);
	else
		return (0);
}

void	swap_top_a(t_vault *data)
{
	if (check_qty_stack_a(data) == 1)
		return ;
	else
	{
		data->nbr_temp = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = data->nbr_temp;
		printf("%s\n", "sa");
	}
}

void	swap_top_b(t_vault *data)
{
	if (check_qty_stack_b(data) == 1)
			return ;
	else
	{
		data->nbr_temp = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = data->nbr_temp;
		printf("%s\n", "sb");
	}
}

void	both_swap_top(t_vault *data)
{
	if (check_qty_stack_a(data) == 0)
	{
		data->nbr_temp = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = data->nbr_temp;
	}
	else if (check_qty_stack_b(data) == 0)
	{
		data->nbr_temp = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = data->nbr_temp;
	}
	else
		return;
	printf("%s\n", "ss");
}
