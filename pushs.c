/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:25:47 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/11 15:49:42 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_vault *data)
{
	unsigned int	x;
	unsigned int	y;

	check_qty_stack_a(data);
	if (data->qty_stack_a == data->index_max)
		return ;
	check_qty_stack_b(data);
	if (data->qty_stack_b == 0)
		return ;
	y = (data->index_max - 1) - data->qty_stack_a;
	x = 0;
	while (data->stack_b[x] == 0)
		x++;
	data->stack_a[y] = data->stack_b[x];
	data->stack_b[x] = 0;
	data->moves++;
	printf("%s\n", "pa");
	stacks_visu(data);  // pour debug visuel
	small_sorting(data);
	return ;
}

void	push_to_b(t_vault *data)
{
	unsigned int	x;
	unsigned int	y;

	check_qty_stack_b(data);
	if (data->qty_stack_b == data->index_max)
		return ;
	check_qty_stack_a(data);
	if (data->qty_stack_a == 0)
		return ;
	y = (data->index_max - 1) - data->qty_stack_b;
	x = 0;
	while (data->stack_a[x] == 0)
		x++;
	data->stack_b[y] = data->stack_a[x];
	data->stack_a[x] = 0;
	data->moves++;
	printf("%s\n", "pb");
	stacks_visu(data); // pour debug visuel
	small_sorting(data);
	return ;
}

