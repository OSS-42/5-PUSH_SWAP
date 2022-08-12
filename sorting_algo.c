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

void	sort_3(t_vault *data)
{
	if (data->stack_a[0] == 3)
	{
		rotate_to_last_a(data);
		check_order_a(data);
		if (data->is_in_order_a == 1)
			return ;
		sort_3(data);
	}
	else if ((data->stack_a[0] == 2 && data->stack_a[1] == 1)
		|| data->stack_a[0] == 1)
		{
			
			swap_top_a(data);
			check_order_a(data);
			if (data->is_in_order_a == 1)
				return ;
			sort_3(data);
		}
	else if (data->stack_a[0] == 2)
	{
		rotate_to_first_a(data);
		check_order_a(data);
		if (data->is_in_order_a == 1)
			return ;
		sort_3(data);
	}
	else
	{
		check_order_a(data);
		printf("%s\n", "c'est déjà trié !");
		return ;
	}
}

void	small_sorting(t_vault *data)
{
	unsigned int	x;

	while (data->moves <= data->index_max)
	{
		x = 0;
		while (data->stack_a[x] == 0)
			x++;
		if (data->stack_a[x] < data->index_max / 2)
		{
			rotate_to_last_a(data);
			check_order_a(data);
			if (data->is_in_order_a == 1)
				return ;
			small_sorting(data);
		}
		else 
		{
			push_to_b(data);
			if (data->qty_stack_b > 1)
			{
				check_order_b(data);
				if (data->is_in_order_b == -1)

			}
			small_sorting(data);
		}
	}
}