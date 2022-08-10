/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:24:43 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/10 11:47:10 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing_numbers(t_vault *data)
{
	unsigned int	x;
	
	x = 0;
	while (x < data->nbr_args)
	{
		data->index = ft_calloc(data->nbr_args, 1);
		
		if (data->args_int[x] < INT_MAX)
		{
			data->min = data->args_int[x];
		}
		printf("%s%u%s%u\n", "index #", x, " : ", data->stack_a[x]);
		x++;
	}
}