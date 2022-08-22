/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:25:03 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/11 13:11:23 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
deferencement en probleme
void	add_to_moves_list(t_vault *data, char *move_name)
{
	t_list	*temp;

	if (ft_lstsize(data->moves_list) == 0)
		*data->moves_list = ft_lstnew(move_name);
	else
	{
		temp = ft_lstnew(move_name);
		ft_lstadd_back(data->moves_list, temp);
	}
}
*/

void	check_qty_stack_b(t_vault *data)
{
	unsigned int	x;
	
	x = 0;
	data->qty_stack_b = 0;
	while (data->stack_b[x] == 0)
		x++;
	while (x < data->index_max)
	{
		data->qty_stack_b++;
		x++;
	}
}

void	check_qty_stack_a(t_vault *data)
{
	unsigned int	x;
	
	x = 0;
	data->qty_stack_a = 0;
	while (data->stack_a[x] == 0)
		x++;
	while (x < data->index_max)
	{
		data->qty_stack_a++;
		x++;
	}
}

void	swap_top_a(t_vault *data)
{
	unsigned int	x;

	x = 0;
	check_qty_stack_a(data);
	if (data->qty_stack_a <= 1)
		return ;
	else
	{
		printf("%s\n", "Swap top A");
		while (data->stack_a[x] == 0)
			x++;
		data->nbr_temp = data->stack_a[x];
		data->stack_a[x] = data->stack_a[x + 1];
		data->stack_a[x + 1] = data->nbr_temp;
		data->moves++;
//		add_to_moves_list(data, "sa");
		printf("%s\n", "sa");
		stacks_visu(data); // pour debug visuel
	}
}

void	swap_top_b(t_vault *data)
{
	unsigned int	x;

	x = 0;
	check_qty_stack_b(data);
	if (data->qty_stack_b <= 1)
		return ;
	else
	{
		printf("%s\n", "Swap top B");
		while (data->stack_b[x] == 0)
			x++;
		data->nbr_temp = data->stack_b[x];
		data->stack_b[x] = data->stack_b[x + 1];
		data->stack_b[x + 1] = data->nbr_temp;
		data->moves++;
//		add_to_moves_list(data, "sa");
		printf("%s\n", "sb");
		stacks_visu(data); // pour debug visuel
	}
}

void	both_swap_top(t_vault *data)
{
	unsigned int	x;

	x = 0;
	check_qty_stack_a(data);
	printf("%s\n", "Swap top A et B");
	if (data->qty_stack_a > 1)
	{
		while (data->stack_a[x] != 0)
			x++;
		data->nbr_temp = data->stack_a[x];
		data->stack_a[x] = data->stack_a[x + 1];
		data->stack_a[x + 1] = data->nbr_temp;
	}
	else if (data->qty_stack_b > 1)
	{
		x = 0;
		while (data->stack_b[x] != 0)
			x++;
		data->nbr_temp = data->stack_b[x];
		data->stack_b[x] = data->stack_b[x + 1];
		data->stack_b[x + 1] = data->nbr_temp;
	}
	else
		return ;
	data->moves++;
//	add_to_moves_list(data, "ss");
	printf("%s\n", "ss");
	stacks_visu(data); // pour debug visuel
}
