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

void	sort_3(t_vault *data)
{
	if (data->stack_a[0] == 3)
	{
		rotate_to_last_a(data);
		check_order_a(data);
		if (data->is_in_order == 1)
			return ;
		sort_3(data);
	}
	else if ((data->stack_a[0] == 2 && data->stack_a[1] == 1)
		|| data->stack_a[0] == 1)
		{
			
			swap_top_a(data);
			check_order_a(data);
			if (data->is_in_order == 1)
				return ;
			sort_3(data);
		}
	else if (data->stack_a[0] == 2)
	{
		rotate_to_first_a(data);
		check_order_a(data);
		if (data->is_in_order == 1)
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
