/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:30:17 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/12 10:30:17 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
lorsque sorting débute, ne pas oublier checker si B est vide avant d'arrêter

A valider : vérifier la 'difficulté' est-ce juste les 2 premiers à switcher ou non ?
*/

void	sort_3_a(t_vault *data)
{
	unsigned int	x;

	x = 0;
	printf("%s\n", "Utilisation de sort_3_a");
	check_qty_stack_a(data);
	check_order_a(data);
	if (data->is_in_order_a == 1)
		return ;
	while (data->stack_a[x] == 0)
		x++;
	is_min_a(data);
	is_max_a(data);
	printf("%s%d\n", "min_a = ", data->is_min_a);
	printf("%s%d\n", "max_a = ", data->is_max_a);
	if (data->qty_stack_a == 2)
		rotate_to_last_a(data);
	else if (data->stack_a[x] == data->is_min_a)
	{
		swap_top_a(data);
		rotate_to_last_a(data);
	}
	else if (data->stack_a[x] == data->is_max_a)
	{
		if (data->stack_a[x + 1] == data->is_min_a)
			rotate_to_last_a(data);
		else
		{
			rotate_to_last_a(data);
			swap_top_a(data);
		}
	}
	else
	{
		if (data->stack_a[x + 1] == data->is_min_a)
			swap_top_a(data);
		else
			rotate_to_first_a(data);
	}
	check_order_a(data);
	return ;
}

void	sort_3_b(t_vault *data) // pas utilisé
{
	unsigned int	x;

	x = 0;
	printf("%s\n", "Utilisation de sort_3_b");
	check_qty_stack_b(data);
	check_order_b(data);
	if (data->is_in_order_b == 1)
		return ;
	while (data->stack_b[x] == 0)
		x++;
	is_min_b(data);
	is_max_b(data);
	if (data->qty_stack_b == 2)
		rotate_to_last_b(data);
	else if (data->stack_b[x] == data->is_min_b)
	{
		swap_top_b(data);
		rotate_to_last_b(data);
	}
	else if (data->stack_b[x] == data->is_max_b)
	{
		if (data->stack_b[x + 1] == data->is_min_b)
			rotate_to_last_b(data);
		else
		{
			rotate_to_last_b(data);
			swap_top_b(data);
		}
	}
	else
	{
		if (data->stack_b[x + 1] == data->is_min_b)
			swap_top_b(data);
		else
			rotate_to_first_b(data);
	}
	check_order_b(data);
	return ;
}

void	sort_4_a(t_vault *data)
{
	unsigned int	x;

	x = 0;
	printf("%s\n", "Utilisation de sort_4_a");
	check_qty_stack_a(data);
	check_order_a(data);
	if (data->is_in_order_a == 1)
		return ;
	while (data->stack_a[x] == 0)
		x++;
	is_min_a(data);
	is_max_a(data);
	if (data->qty_stack_a == 2)
		rotate_to_last_a(data);
	if (data->qty_stack_a == 3)
		sort_3_a(data);
	else if (data->stack_a[x] == data->is_min_a)
	{
		push_to_b(data);
		sort_3_a(data);
		push_to_a(data);
	}
	else if (data->stack_a[x] == data->is_max_a)
	{
		if (data->stack_a[x + 1] == data->is_min_a)
			rotate_to_last_a(data);
		else 
		{
			rotate_to_first_a(data);
			sort_4_a(data);
		}
	}
	else if (data->stack_a[x + 1] == data->is_min_a)
	{
		swap_top_a(data);
		sort_4_a(data);
	}
	else
	{
		rotate_to_first_a(data);
		sort_4_a(data);
	}
	check_order_a(data);
}

void	sort_5(t_vault *data)
{
	unsigned int	x;
	unsigned int	y;

	printf("%s\n", "Utilisation de sort_5");	
	check_qty_stack_a(data);
	while (data->qty_stack_a > 3)
	{
		check_qty_stack_a(data);
		printf("%s%d\n",  "qty A:", data->qty_stack_a);
		x = 0;
		while (data->stack_a[x] == 0)
			x++;
		if (data->qty_stack_a == 3)
			break ;
		if (data->stack_a[x] > data->index_max / 2)
			rotate_to_last_a(data);
		else if (data->stack_a[x] <= data->index_max / 2)
			push_to_b(data);
	}
	sort_3_a(data);
	check_qty_stack_b(data);
	is_max_b(data);
	y = 0;
	while (data->stack_b[y] == 0)
		y++;
	if (data->stack_b[y] != data->is_max_b)
		rotate_to_first_b(data);
	while (data->qty_stack_b > 0)
	{
		push_to_a(data);
		check_qty_stack_b(data);
		check_order_a(data);
		if (data->moves > 0 && data->is_in_order_a == 1 && data->qty_stack_b == 0)
		{
			printf("%s\n", "liste complètement triée !");
			return ;
		}
	}
	return ;
}

void	sort_100(t_vault *data)
{
	unsigned int	x;

	check_order_a(data);
	if (data->is_in_order_a == 1)
		return ;
	printf("%s\n", "Utilisation de sort_100");	
	check_qty_stack_a(data);
	while (data->qty_stack_a > 3)
	{
		check_qty_stack_a(data);
		printf("%s%d\n",  "qty A:", data->qty_stack_a);
		x = 0;
		while (data->stack_a[x] == 0)
			x++;
		data->pivot = (data->qty_stack_a / 2 + x);
		if (data->stack_a[x] > data->pivot)
			rotate_to_last_a(data);
		else if (data->stack_a[x] <= data->pivot)
			push_to_b(data);
	}
	sort_3_a(data);
	check_qty_stack_b(data);
	while (data->qty_stack_b > 0)
	{
		check_qty_stack_a(data);
		check_order_a(data);
		is_min_a(data);
		if (data->is_in_order_a == 1)
			data->cost_a_to_top = 0;
		else if (data->min_a_pos <= (data->index_max - (data->qty_stack_a / 2) - 1))
			data->cost_a_to_top = data->min_a_pos - ((data->index_max - 1) - (data->qty_stack_a - 1));
		else
			data->cost_a_to_top = data->min_a_pos - (data->index_max - 1);
		check_qty_stack_b(data);
		check_reverse_order_b(data);
		is_max_b(data);
//		check_qty_stack_b(data);
		printf("%s%d\n", "max pos b : ", data->max_b_pos);
		if (data->is_in_order_b == -2)
			data->cost_b_to_top = 0;
		else if (data->max_b_pos <= (data->index_max - (data->qty_stack_b / 2 ) - 1))
		{
			printf("AAA\n");
			data->cost_b_to_top = data->max_b_pos - ((data->index_max - 1) - (data->qty_stack_b - 1));
		}
		else
		{
			printf("BBB\n");
			data->cost_b_to_top = data->max_b_pos - (data->index_max);
		}
		printf("%s%d\n", "cost_to_top_a : ", data->cost_a_to_top);
		printf("%s%d\n", "cost_to_top_b : ", data->cost_b_to_top);
		while (abs(data->cost_a_to_top) + abs(data->cost_b_to_top) != 0)
		{
			printf("%s%d\n", "cost_to_top_a : ", data->cost_a_to_top);
			printf("%s%d\n", "cost_to_top_b : ", data->cost_b_to_top);
			printf("%s%d\n", "max pos b : ", data->max_b_pos);
			if (data->cost_a_to_top < 0 && data->cost_b_to_top < 0)
			{
				rotate_both_to_first(data);
				data->cost_a_to_top += 1;
				data->cost_b_to_top += 1;
			}
			else if (data->cost_a_to_top > 0 && data->cost_b_to_top > 0)
			{
				rotate_both_to_last(data);
				data->cost_a_to_top -= 1;
				data->cost_b_to_top -= 1;
			}
			else if (data->cost_a_to_top > 0)
			{
				rotate_to_last_a(data);
				data->cost_a_to_top -= 1;
			}
			else if (data->cost_a_to_top < 0)
			{
				rotate_to_first_a(data);
				data->cost_a_to_top += 1;
			}
			else if (data->cost_b_to_top > 0)
			{
				rotate_to_last_b(data);
				data->cost_b_to_top = data->cost_b_to_top - 1;
			}
			else
			{
				rotate_to_first_b(data);
				data->cost_b_to_top += 1;
			}
		}
		push_to_a(data);
		check_qty_stack_b(data);
	}
	check_order_a(data);
	if (data->is_in_order_a == 1 && data->moves > 0)
	{
		printf("%s\n", "liste complètement triée !");
		return ;
	}
}
