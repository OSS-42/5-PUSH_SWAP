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

/*
fonctionnement avec binaires (Radix sort), efficacité à prouver. idéal à > 128 ?
watch for pa/pb inutiles en fin de boucle lors du sorting de A (dernière valeur à faire pa)

long long	convert(t_vault *data, int n)
{	
	long long	bin;
	int 		rem;
	int 		i;

	bin = 0;
	rem = 1;
	i = 1;
	while (n != 0)
	{
		rem = n % 2;
		n = n / 2;
		bin = bin + rem * i;
		i = i * 10;
	}
	return bin;
}
*/

void	algo_choice(t_vault *data)
{
	check_order_a(data);
	if (data->is_in_order_a == 1)
		return ;
	printf("%s\n", "liste non triée, commencons...");
	data->stack_b = ft_calloc(data->index, 10);
	data->moves = 0;
	if (data->index_max <= 3)
		sort_3_a(data);
	else if (data->index_max == 4)
		sort_4_a(data);
	else if (data->index_max == 5)
		sort_5(data);
	else if (data->index_max > 5 && data->index_max <= 100)
	{
		printf("%s\n", "let's do sort_100");
		sort_100(data);
	}
	else if (data->index_max > 100 && data->index_max <= 500)
	{
		printf("%s\n", "algo sort_500 pas encore prêt");
	}
	free (data->stack_b);
	return ;
}

void	indexing_numbers(t_vault *data)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	data->index = 1;
	data->position = 0;
	data->switches = ft_calloc(data->nbr_args, 10);
	data->stack_a = ft_calloc(data->nbr_args, 10);
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
	data->is_in_order_a = 0;
	algo_choice(data);
	free (data->stack_a);
	free (data->switches);
	free (data->args_int);
	return ;
}
