/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:24:43 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/10 15:55:24 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
chaque nombre doit obtenir son index par rapport aux autres nombres.
Il suffit ensuite de remettre l'index en ordre.
*/

void	indexing_numbers(t_vault *data)
{
	unsigned int	x;
	unsigned int	y;
	
	x = 0;
	y = 0;
	data->index = 0;
	data->position = 0;
	data->switches = ft_calloc(data->nbr_args, 1);
	data->stack_a = malloc(sizeof(unsigned int *) * data->nbr_args);
	data->min = data->args_int[x];
	x = 1;
	while (y < data->nbr_args)
	{
		while (x < data->nbr_args)
		{
			if (data->min < data->args_int[x] && data->switches[x] == 0)
			{
				data->position = x;
				data->min = data->args_int[x];
				data->switches[x] = 1;
			}
			printf("%s%ld\n", "min actuel : ", data->min);
			printf("%s%ld\n", "chiffre traité : ", data->args_int[x]);
			printf("%s%d\n", "position x : ", data->position);
			printf("%s%d\n", "switch actuel : ", data->switches[x]);
			x++;
		}
		data->stack_a[data->position] = data->index;
		x = 0;
		data->position = 0;
		y++;
	}
}