/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:23:50 by ewurstei          #+#    #+#             */
/*   Updated: 2022/09/15 14:22:14 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both_to_first(t_vault *data)
{
	data->is_it_both = 1;
	rotate_to_first_a(data);
	rotate_to_first_b(data);
	data->is_it_both = 0;
	data->moves -= 1;
	printf("%s\n", "rrr");
}

void	rotate_both_to_last(t_vault *data)
{
	data->is_it_both = 1;
	rotate_to_last_a(data);
	rotate_to_last_b(data);
	data->is_it_both = 0;
	data->moves -= 1;
	printf("%s\n", "rr");
}
