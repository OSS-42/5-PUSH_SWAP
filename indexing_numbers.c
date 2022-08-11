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
	unsigned int	boucle;

	x = 0;
	y = 0;
	data->index = 0;
	data->position = 0;
	data->switches = ft_calloc(data->nbr_args, 1);
	data->stack_a = malloc(sizeof(unsigned int *) * data->nbr_args);
	if (!data->stack_a)
		return ;
	data->min = data->args_int[x];
	x = 1;
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
	boucle = 0;
	while (boucle < data->nbr_args)
	{
		printf("%s%d%s%d%s%ld\n", "stack_a#", boucle, " : ", data->stack_a[boucle], " - arg = ", data->args_int[boucle]);
		boucle++;
	}
	printf("%s\n", "rendu la, on peut commencer le triage !");
	sorting_numbers(data);
}
