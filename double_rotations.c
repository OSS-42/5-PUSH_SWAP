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

void	rotate_both_to_first(t_vault *data)
{
	unsigned int	x;

	x = data->index_max - 1;
	check_qty_stack_a(data);
	if (data->qty_stack_a == 1 || data->qty_stack_a == 0)
		return ;
	while (x > 0 && data->stack_a[x] != 0)
	{
		data->nbr_temp = data->stack_a[x];
		data->stack_a[x] = data->stack_a[x - 1];
		data->stack_a[x - 1] = data->nbr_temp;
		x--;
	}
	check_qty_stack_a(data);
	if (data->qty_stack_a == 1 || data->qty_stack_a == 0)
		return ;
	x = data->index_max - 1;
	while (x > 0 && data->stack_b[x] != 0)
	{
		data->nbr_temp = data->stack_b[x];
		data->stack_b[x] = data->stack_b[x - 1];
		data->stack_b[x - 1] = data->nbr_temp;
		x--;
	}
	data->moves++;
//	add_to_moves_list(data, "rrr");
	printf("%s\n", "rrr");
//	stacks_visu(data);
}

void	rotate_both_to_last(t_vault *data)
{
	unsigned int	x;

	x = 0;
	check_qty_stack_a(data);
	if (data->qty_stack_a == 1 || data->qty_stack_a == 0)
		return ;
	while (data->stack_a[x] == 0)
			x++;
	while (x < data->index_max - 1 && data->stack_a[x] != 0)
	{
		data->nbr_temp = data->stack_a[x];
		data->stack_a[x] = data->stack_a[x + 1];
		data->stack_a[x + 1] = data->nbr_temp;
		x++;
	}
	check_qty_stack_a(data);
	if (data->qty_stack_a == 1 || data->qty_stack_a == 0)
		return ;
	x = 0;
	while (data->stack_b[x] == 0)
		x++;
	while (x < data->index_max - 1 && data->stack_b[x] != 0)
	{
		data->nbr_temp = data->stack_b[x];
		data->stack_b[x] = data->stack_b[x + 1];
		data->stack_b[x + 1] = data->nbr_temp;
		x++;
	}
	data->moves++;
//	add_to_moves_list(data, "rr");
	printf("%s\n", "rr");
//	stacks_visu(data);
}
