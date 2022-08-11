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
chaque nombre doit obtenir son index par rapport aux autres nombres.
Il suffit ensuite de remettre l'index en ordre.
*/

static void	check_index(t_vault *data)
{
	unsigned int	boucle;

	boucle = 0;
	while (boucle < data->nbr_args)
	{
		printf("%s%d%s%d%s%ld\n", "stack_a#", boucle, " : ", data->stack_a[boucle], " - arg = ", data->args_int[boucle]);
		boucle++;
	}
	printf("%s\n", "rendu la, on peut commencer le triage !");
}

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
	data->min = data->args_int[x];
	x = 1;
	printf("%s%d\n", "nbr args :", data->nbr_args);
	while (y < data->nbr_args)
	{
		while (x < data->nbr_args)
		{
			if (data->switches[x] != 0)
				x++;
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
	sorting_numbers(data);
}
