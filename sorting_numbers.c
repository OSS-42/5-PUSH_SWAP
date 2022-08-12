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
envisager d<utiliser des algos differents selon la quantite de nombres
*/
/*
static int	check_order_b(t_vault *data)
{
	unsigned int	x;
	
	x = 0;
	printf("%s\n", "checkons l'ordre de b");
	printf("%s%d\n", "data->index = : ", data->index);
	while (x < data->index - 1)
	{
		printf("%s%d\n", "stack position : ", x);
		printf("%s%d\n", "index : ", data->stack_b[x]);
		if (data->stack_b[x] > data->stack_b[x + 1])
		{
			printf("%d%s%d\n", data->stack_b[x], " est plus grand que ", data->stack_b[x + 1]);
			printf("%s\n", "hello");
			return (1);
		}
		else
			x++;
	}
	return (0);
}
*/
static int	check_order_a(t_vault *data)
{
	unsigned int	x;
	
	x = 0;
	printf("%s\n", "checkons l'ordre de a");
	printf("%s%d\n", "data->index = : ", data->index);
	while (x < data->index - 1)
	{
		printf("%s%d\n", "stack position : ", x);
		printf("%s%d\n", "index : ", data->stack_a[x]);
		if (data->stack_a[x] > data->stack_a[x + 1])
		{
			printf("%d%s%d\n", data->stack_a[x], " est plus grand que ", data->stack_a[x + 1]);
			return (1);
		}
		else
			x++;
	}
	return (0);
}

void	small_sorting(t_vault *data)
{
	unsigned int	x;

	x = 0;
	if (data->stack_a[x] == 0)
		x++;
	while (x < data->index - 1)
	{
		if (data->stack_a[x] < data->index / 2)
			push_to_b(data);
		else if (data->stack_a[x] > data->index / 2)
			rotate_to_last_a(data);	
		x++;
	}
}

void	sorting_numbers(t_vault *data)
{
	data->index -= 1;
	if (check_order_a(data) == 0)
	{
		printf("%s\n", "c'est déjà trié !");
		return ;
	}
	printf("%s\n", "liste non triée, commencons...");
	data->stack_b = ft_calloc(data->index, 1);
	stacks_visu(data); // debug visuel
	if (data->index < 10)
		small_sorting(data);
	else
		return ;
		//normal_sorting(data);

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