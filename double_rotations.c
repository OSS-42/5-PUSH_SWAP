/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:23:50 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/11 13:44:16 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_rotate_to_first(t_vault *data)
{
	unsigned int	x;

	x = data->index - 1;
	if (check_qty_stack_a(data) == 0)
	{
		while (x > 0 && data->stack_a[x] != 0)
		{
			data->nbr_temp = data->stack_a[x];
			data->stack_a[x] = data->stack_a[x - 1];
			data->stack_a[x - 1] = data->nbr_temp;
			x--;
		}
	}
	if (check_qty_stack_b(data) == 0)
	{
		x = data->index - 1;
		while (x > 0 && data->stack_b[x] != 0)
		{
			data->nbr_temp = data->stack_b[x];
			data->stack_b[x] = data->stack_b[x - 1];
			data->stack_b[x - 1] = data->nbr_temp;
			x--;
		}
	}
	return ;
	printf("%s\n", "rrr");
}

void	both_rotate_to_last(t_vault *data)
{
	unsigned int	x;

	x = 0;
	if (check_qty_stack_a(data) == 0)
	{
		while (x < data->index && data->stack_a[x] != 0)
		{
			data->nbr_temp = data->stack_a[x];
			data->stack_a[x] = data->stack_a[x + 1];
			data->stack_a[x + 1] = data->nbr_temp;
			x++;
		}
	}
	if (check_qty_stack_b(data) == 0)
	{
		x = 0;
		while (x < data->index && data->stack_b[x] != 0)
		{
			data->nbr_temp = data->stack_b[x];
			data->stack_b[x] = data->stack_b[x + 1];
			data->stack_b[x + 1] = data->nbr_temp;
			x++;
		}
	}
	return ;
	printf("%s\n", "rr");
}
