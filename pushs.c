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
	unsigned int	z;

	y = (data->index - 1) - data->qty_stack_a;
	z = (data->index - 1) - data->qty_stack_b;
	x = 0;
	while (data->stack_a[x] == 0)
		x++;
	data->stack_b[y] = data->stack_a[x];
	data->stack_a[x] = 0;
	printf("%s\n", "pa");
}

void	push_to_b(t_vault *data)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	z;

	y = (data->index - 1) - data->qty_stack_b;
	z = (data->index - 1) - data->qty_stack_a;
	x = 0;
	while (data->stack_b[x] == 0)
		x++;
	data->stack_a[y] = data->stack_b[x];
	data->stack_b[x] = 0;
	printf("%s\n", "pb");
}

void	stacks_visu(t_vault *data)
{
	unsigned int	x;

	x = 0;
	printf("%s%s%s\n", "A", "	", "B");
	while (x < data->index)
	{
		printf("%d%s%d\n", data->stack_a[x], "	", data->stack_b[x]);
		x++;
	}
}