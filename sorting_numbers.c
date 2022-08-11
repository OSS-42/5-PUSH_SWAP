/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:03:54 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/10 22:03:54 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
envisager d<utiliser des algos differents selon la quantite de nombres
*/

static int	check_order(t_vault *data)
{
	unsigned int	x;
	x = 0;
	while (x < data->index)
	{
		if (data->stack_a[x + 1] != (data->stack_a[x] + 1))
			return (1);
		else
			x++;
	}
	return (0);
}

static void	small_sorting(t_vault *data)
{
	unsigned int	x;

	x = 0;
	while (x <= data->index)
	{
		if (data->stack_a[x] < data->index / 2)
			push_to_b(data);
		else if (data->stack_a[x] > data->index /2)
			rotate_to_last_a(data);
		
	}
}

void	sorting_numbers(t_vault *data)
{
	if (data->index > 10)
		small_sorting(data);
	else
		normal_sorting(data);
}

/*
	rotate_to_last_b(data);
	rotate_to_first_a(data);
	rotate_to_first_b(data);
	push_to_a(data);
	swap_top_a(data);
	swap_top_b(data);
	double_rotate_to_first(data);
	double_rotate_to_back(data);
	double_swap_top(data);

	check_order(data);
*/