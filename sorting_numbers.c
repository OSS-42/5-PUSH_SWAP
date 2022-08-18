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

/*
envisager d'utiliser des algos differents selon la quantite de nombres
*/
void	check_order_b(t_vault *data)
{
	unsigned int	x;
	
	x = 0;
	printf("%s\n", "checkons l'ordre croissant de B");
	printf("%s%d\n", "index max = ", data->index_max);
	while (data->stack_b[x] == 0)
		x++;
	while (x < data->index_max - 1)
	{
		printf("%s%d\n", "stack position : ", x);
		printf("%s%d\n", "index : ", data->stack_b[x]);
		printf("%s%d\n", "next index : ", data->stack_b[x + 1]);
		if (data->stack_b[x] > data->stack_b[x + 1])
		{
			printf("%s\n", "B est dans le désordre");
			data->is_in_order_b = -1;
			return ;
		}
		else
			x++;
	}
	data->is_in_order_b = 1;
	printf("%s\n", "B est en ordre croissant !");
	return ;
}

void	check_order_a(t_vault *data)
{
	unsigned int	x;
	
	x = 0;
	printf("%s\n", "checkons l'ordre croissant de A");
	printf("%s%d\n", "index max = ", data->index_max);
	stacks_visu(data);
	while (data->stack_a[x] == 0)
		x++;
	while (x < data->index_max - 1)
	{
		printf("%s%d\n", "stack position : ", x);
		printf("%s%d\n", "index : ", data->stack_a[x]);
		printf("%s%d\n", "next index : ", data->stack_a[x + 1]);
		if (data->stack_a[x] > data->stack_a[x + 1])
		{
			printf("%s\n", "A est dans le désordre");
			data->is_in_order_a = -1;
			data->difficulty = x;
			return ;
		}
		else
			x++;
	}
	data->is_in_order_a = 1;
	printf("%s\n", "A est en ordre croissant !");
	return ;
}

void	is_min_a(t_vault *data)
{
	unsigned int	x;

	x = 0;
	while (data->stack_a[x] == 0)
		x++;
	data->is_min_a = data->stack_a[x];
	x++;
	while (x < data->index_max)
	{
		if (data->stack_a[x] < data->is_min_a)
			data->is_min_a = data->stack_a[x];
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
	x++;
	while (x < data->index_max)
	{
		if (data->stack_b[x] > data->is_max_b)
			data->is_max_b = data->stack_b[x];
		else
			x++;
	}
	return ;
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