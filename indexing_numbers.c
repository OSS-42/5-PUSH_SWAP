/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:24:43 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/11 16:14:50 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Chaque nombre doit obtenir son index par rapport aux autres nombres.
L'indexation start à 1 pour que 0 = faux 'null' pendant le triage
*/

void	indexing_numbers(t_vault *data)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	data->index = 1;
	data->position = 0;
	data->switches = ft_calloc(data->nbr_args, 1);
	data->stack_a = ft_calloc(data->nbr_args, 1);
	data->min = INT_MAX;
	printf("%s%d\n", "2.nbr args :", data->nbr_args);
	while (y < data->nbr_args)
	{
		while (x < data->nbr_args)
		{
			if (data->min > data->args_int[x] && data->switches[x] == 0)
			{
				data->position = x;
				data->min = data->args_int[x];
			}
			x++;
		}
		data->switches[data->position] = 1;
		data->stack_a[data->position] = data->index;
		x = 0;
		while (data->switches[x] == 1)
			x++;
		data->index++;
		data->position = x;
		data->min = data->args_int[x];
		y++;
	}
	check_index(data); //debug visualisation
	data->index_max = data->index - 1;
	data->is_in_order = 0;
	sorting_numbers(data);
}
