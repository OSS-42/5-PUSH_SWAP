/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:32:46 by ewurstei          #+#    #+#             */
/*   Updated: 2022/09/16 11:40:43 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	sort_100_clean_a(t_vault *data)
{
	unsigned int	x;

	check_qty_stack_a(data);
	while (data->qty_stack_a > 3)
	{
		x = position_x_a(data);
		if (data->stack_a[x] != data->index_max
			&& data->stack_a[x] != data->index_max - 1
			&& data->stack_a[x] != data->index_max - 2)
			push_to_b(data);
		else
			rotate_to_last_a(data);
		check_qty_stack_a(data);
	}
	sort_3_init(data);
}
*/

void	sort_100_a_to_b(t_vault *data)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	div;

	check_qty_stack_a(data);
	div = data->qty_stack_a / 4;
	while (data->qty_stack_a > 3 /*&& div > 0*/)
	{
		data->round = data->qty_stack_a;
		while (data->round > 0 && data->qty_stack_a > 3)
		{
			x = position_x_a(data);
//			printf("%s%d\n", "div : ", div);
//			printf("%s%d\n", "x : ", data->stack_a[x]);
//			stacks_visu(data);
			if (data->stack_a[x] > div && data->stack_a[x] <= data->index_max - div && data->stack_a[x] <= data->index_max - 3)
			{
				push_to_b(data);
				y = position_x_b(data);
				if (data->stack_b[y] <= data->index_max / 2)
				{
					rotate_to_last_b(data);
//					stacks_visu(data);
				}
				else if (data->stack_b[y] < data->stack_b[y + 1])
				{
					swap_top_b(data);
//					stacks_visu(data);
				}
			}
			else
			{
				rotate_to_last_a(data);
//				stacks_visu(data);
			}
			data->round--;
			check_qty_stack_a(data);
		}
		check_qty_stack_a(data);
		div /= 2;
	}
//	stacks_visu(data);
	sort_3_init(data);
}

/*
void	sort_100_a_to_b(t_vault *data)
{
	unsigned int	y;
	unsigned int	x;

	check_qty_stack_a(data);
	check_qty_stack_b(data);
	y = 1;
	while (y <= data->pivot_round)
	{
		while (data->qty_stack_b < data->pivot * y && data->qty_stack_a > 3)
		{
			x = position_x_a(data);
			determine_next_move_in_a(data, y);
			if (data->stack_a[x] <= data->pivot * y
				|| data->stack_a[x] != data->index_max
				|| data->stack_a[x] != data->index_max - 1
				|| data->stack_a[x] != data->index_max - 2)
				push_to_b(data);
			smart_sort_b(data);
			check_qty_stack_a(data);
			check_qty_stack_b(data);
		}
		y++;
	}
}
*/

void	sort_100_b_to_a(t_vault *data)
{
	unsigned int	x;
	
	check_qty_stack_b(data);
	while (data->qty_stack_b > 0)
	{
		moves_cost_max_in_a(data);
		check_before_max_b(data);
		while (abs(data->cost_a_to_top) + abs(data->cost_b_to_top) != 0)
			moves_b_to_a(data);
		push_to_a(data);
		is_min_a(data);
		x = position_x_a(data);
		if (data->stack_a[x] == data->is_min_a + 1)
			swap_top_a(data);
		check_qty_stack_b(data);
	}
}

/* regarder pour optimiser le sort_100 */
void	sort_100(t_vault *data)
{
//	determine_pivot(data);
//	stacks_visu(data);
	sort_100_a_to_b(data);
//	sort_100_clean_a(data);
	sort_100_b_to_a(data);
	check_order_a(data);
	if (data->is_in_order_a == 1 && data->moves > 0)
		return ;
}

/* 
bad test case - previous : 836
-374023161 -1976210252 1558896418 221485737 1570318679 254915417 -2012513326 -657949150 118462530 -989613381 -429078248 130891857 1908299670 564895403 -1186889594 -1107186109 1980316639 426688536 1421843413 -1191398347 -1409014840 -1469534596 -1162273742 -361031605 984826552 527859710 5056022 1450525896 546674252 832790252 -1787315714 -515963112 45967969 -1045102791 1304233012 -1741257359 1773618572 65415649 -166030905 -1787208793 -173007688 460952512 -1659483862 -2008030260 1898197159 -699441591 -584629128 254743793 1586045905 702566187 -1790745997 1774228627 -1528584447 -725820758 -103121125 -198883724 -884653900 -1900495346 2113943356 -1584498632 -448468504 -1404008825 -1306097858 -1774242512 347916692 1968798290 769466085 771761099 -2140728589 217956973 -11769107 1954572778 -1195544971 2070090968 -669455357 1317772155 -63091200 137060079 276866544 720109037 -1682963856 -556604323 -1964169427 666229118 1494367505 314501744 1367807293 -1537033613 1092686530 542623765 -509660668 267667137 -1474706267 886382985 -967094405 -273749601 -943574644 634007724 -1280043418 -1422213194
*/