/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:30:17 by ewurstei          #+#    #+#             */
/*   Updated: 2022/09/12 16:23:52 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_loop(t_vault *data, unsigned int x)
{
	if (data->qty_stack_a == 2)
		rotate_to_last_a(data);
	else if (data->stack_a[x] == data->is_min_a)
	{
		swap_top_a(data);
		rotate_to_last_a(data);
	}
	else if (data->stack_a[x] == data->is_max_a)
	{
		if (data->stack_a[x + 1] == data->is_min_a)
			rotate_to_last_a(data);
		else
		{
			rotate_to_last_a(data);
			swap_top_a(data);
		}
	}
	else
	{
		if (data->stack_a[x + 1] == data->is_min_a)
			swap_top_a(data);
		else
			rotate_to_first_a(data);
	}
	return ;
}

void	sort_3_init(t_vault *data)
{
	unsigned int	x;

	x = 0;
	check_qty_stack_a(data);
	check_order_a(data);
	if (data->is_in_order_a == 1)
		return ;
	while (data->stack_a[x] == 0)
		x++;
	is_min_a(data);
	is_max_a(data);
	sort_3_loop(data, x);
	check_order_a(data);
	return ;
}

void	sort_5_part2(t_vault *data, unsigned int x)
{
	check_qty_stack_b(data);
	check_reverse_order_b(data);
	if (data->is_in_order_b != -2)
		rotate_to_last_b(data);
	while (data->qty_stack_b > 0)
	{
		push_to_a(data);
		x = 0;
		while (data->stack_a[x] == 0)
			x++;
		if (data->stack_a[x] > data->stack_a[x + 1])
			swap_top_a(data);
		check_qty_stack_b(data);
		check_order_a(data);
		if (data->moves > 0 && data->is_in_order_a == 1
			&& data->qty_stack_b == 0)
			return ;
	}
	return ;
}

void	sort_5(t_vault *data)
{
	unsigned int	x;

	check_qty_stack_a(data);
	while (data->qty_stack_a > 3)
	{
		x = 0;
		while (data->stack_a[x] == 0)
			x++;
		check_order_a(data);
		if (data->is_in_order_a == 1 && data->qty_stack_a == data->index_max)
			break ;
		if (data->stack_a[x] > data->qty_stack_a / 2 + x)
			rotate_to_last_a(data);
		else if (data->stack_a[x] <= data->qty_stack_a / 2 + x)
			push_to_b(data);
		check_qty_stack_a(data);
	}
	if (data->is_in_order_a == 1 && data->qty_stack_a == data->index_max)
		return ;
	sort_3_init(data);
	sort_5_part2(data, x);
	return ;
}

/*
unsigned int	position_in_a(t_vault *data)
{
	unsigned int	x;

	x = 0;
	while (data->stack_a[x] == 0)
		x++;
	return (x);
}
*/

void	sort_100(t_vault *data) // a revoir
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	z;

	check_order_a(data);
	if (data->is_in_order_a == 1)
		return ;
	if (data->index_max <= 20)
	{
		data->pivot = data->index_max / 2;
		data->pivot_round = 2;
	}
	if (data->index_max > 20 && data->index_max <= 100)
	{
		data->pivot = data->index_max / 8;
		data->pivot_round = 8;
	}
	if (data->index_max > 100 && data->index_max <= 500)
	{
		data->pivot = data->index_max / 10;
		data->pivot_round = 10;
	}
	check_qty_stack_a(data);
	check_qty_stack_b(data);
	y = 1;
	while (y <= data->pivot_round)
	{
		while (data->qty_stack_b < data->pivot * y && data->qty_stack_a > 3)
		{
			x = 0;
			while (data->stack_a[x] == 0)
				x++;
			check_order_a(data);
			is_min_a(data);
			is_max_b(data);
			check_qty_stack_b(data);
			next_move_stack_a(data, y);
//			stacks_visu(data);
//			printf("%s%d\n", "next nbr ra : ", data->next_nbr_ra);
//			printf("%s%d\n", "next nbr rra : ", data->next_nbr_rra);
//			if (data->stack_a[x + 1] == data->is_min_a)
//				swap_top_a(data);
			if (data->next_nbr_ra < data->next_nbr_rra || data->next_nbr_ra == data->next_nbr_rra)
			{
				while (data->next_nbr_ra > 0)
				{
					rotate_to_last_a(data);
					data->next_nbr_ra--;
				}
			}
			else if (data->next_nbr_ra > data->next_nbr_rra)
			{
				while (data->next_nbr_rra > 0)
				{
					rotate_to_first_a(data);
					data->next_nbr_rra--;
				}
			}
//			else if (data->stack_a[x] > data->stack_a[data->index_max - 1] && data->stack_a[data->index_max - 1] < data->stack_a[x + 1] && data->stack_a[x] <= data->pivot * y)
//				rotate_to_first_a(data);
//			if (data->stack_a[x] > data->pivot * y)
//				rotate_to_last_a(data);
			if (data->stack_a[x] <= data->pivot * y
				|| data->stack_a[x] != data->index_max
				|| data->stack_a[x] != data->index_max - 1
				|| data->stack_a[x] != data->index_max - 2)
					push_to_b(data);
//			stacks_visu(data);
			check_qty_stack_b(data);
			x = 0;
			while (data->stack_b[x] == 0)
				x++;
			if ((data->stack_b[x] < data->qty_stack_b / 3
				&& data->stack_b[x] < data->stack_b[x + 1])
				|| data->stack_b[x] == 1)
					rotate_to_last_b(data);
			else if (data->stack_b[x] < data->stack_b[x + 1])
				swap_top_b(data);
//			stacks_visu(data);
			check_qty_stack_a(data);
			check_qty_stack_b(data);		
		}
		y++;
//		printf("%s\n", "next loop");
	} 
//	printf("%s\n", "sort 3");
	check_qty_stack_a(data);
	if (data->qty_stack_a > 3 && data->qty_stack_a <= 5)
	{
		while (data->qty_stack_a > 3)
		{
			push_to_b(data);
			check_qty_stack_a(data);
		}
	}
	sort_3_init(data);
//	stacks_visu(data);
	while (data->qty_stack_b > 0)
	{
//		stacks_visu(data);
		check_qty_stack_a(data);
		check_order_a(data);
		x = 0;
		while (data->stack_a[x] == 0)
			x++;
		y = 0;
		while (data->stack_b[y] == 0)
			y++;
		is_min_a(data);
		is_max_b(data);
		z = 0;
		while (data->is_min_a < data->is_max_b)
		{
			x = 0;
			while (data->stack_a[x] == 0)
				x++;
			y = 0;
			while (data->stack_b[y] == 0)
				y++;
//			stacks_visu(data);
			if (data->stack_b[y] == data->index_max)
			{
				push_to_a(data);
				rotate_to_last_a(data);
//				stacks_visu(data);
			}
			else if (data->stack_a[x] < data->stack_b[y] && data->stack_a[x + 1] < data->stack_b[y])
			{
				rotate_to_last_a(data);
//				stacks_visu(data);
				z++;
			}
			else if (data->stack_a[x] < data->stack_b[y] && data->stack_a[x + 1] > data->stack_b[y])
			{
				rotate_to_last_a(data);
				push_to_a(data);
//				stacks_visu(data);
				z++;
			}
			else
			{
//				stacks_visu(data);
				is_min_a(data);
				is_max_b(data);
				check_qty_stack_a(data);
				if (data->is_in_order_a == 1)
					data->cost_a_to_top = 0;
				else if (data->min_a_pos <= (data->index_max - (data->qty_stack_a / 2) - 1))
					data->cost_a_to_top = data->min_a_pos - ((data->index_max - 1) - (data->qty_stack_a - 1));
				else
					data->cost_a_to_top = data->min_a_pos - (data->index_max - 1);
				check_qty_stack_b(data);
				check_reverse_order_b(data);
				if (data->is_in_order_b == -2)
					data->cost_b_to_top = 0;
				else if (data->max_b_pos <= (data->index_max - (data->qty_stack_b / 2) - 1))
					data->cost_b_to_top = data->max_b_pos - ((data->index_max - 1) - (data->qty_stack_b - 1));
				else
					data->cost_b_to_top = data->max_b_pos - (data->index_max);
//				printf("%s%d\n", "1.cost a :", data->cost_a_to_top);
//				printf("%s%d\n", "1.cost b :", data->cost_b_to_top);
				break ;
			}
			while (z > 0 && data->stack_a[x] > data->stack_b[y])
			{
				if (data->stack_a[x - 1] == data->stack_b[y])
					push_to_a(data);
				rotate_to_first_a(data);
//				stacks_visu(data);
				z--;
			}
//			stacks_visu(data);
			is_min_a(data);
			is_max_b(data);
//			printf("%s%d\n", "min a : ", data->is_min_a);
//			printf("%s%d\n", "max b : ", data->is_max_b);
		}
//		stacks_visu(data);
		check_qty_stack_a(data);
		check_order_a(data);
		is_min_a(data);
		is_max_b(data);
//		printf("%s%d\n", "pos min a : ", data->min_a_pos);
//		printf("%s%d\n", "pos max b : ", data->max_b_pos);
//		printf("%s%d\n", "is A in order ? ", data->is_in_order_a);
		if (data->is_in_order_a == 1 && data->is_min_a > data->is_max_b)
			data->cost_a_to_top = 0;
		else if (data->is_min_a + 1 == data->is_max_b /*&& data->stack_a[data->min_a_pos + 1] != data->is_min_a + 1*/)
			data->cost_a_to_top = 1;
		else if (data->min_a_pos <= (data->index_max - (data->qty_stack_a / 2) - 1))
			data->cost_a_to_top = data->min_a_pos - ((data->index_max - 1) - (data->qty_stack_a - 1));
		else if (data->min_a_pos == data->index_max - 1)
			data->cost_a_to_top = -1;
		else
			data->cost_a_to_top = data->min_a_pos - (data->index_max - 1);
		check_qty_stack_b(data);
		check_reverse_order_b(data);
		if (data->is_in_order_b == -2)
			data->cost_b_to_top = 0;
		else if (data->max_b_pos <= (data->index_max - (data->qty_stack_b / 2) - 1))
			data->cost_b_to_top = data->max_b_pos - ((data->index_max - 1) - (data->qty_stack_b - 1));
		else
			data->cost_b_to_top = data->max_b_pos - (data->index_max);
//		printf("%s%d\n", "2.cost a :", data->cost_a_to_top);
//		printf("%s%d\n", "2.cost b :", data->cost_b_to_top);
//		stacks_visu(data);
//		exit (0);
//		printf("%s%d\n", "1.cost a :", data->cost_a_to_top);
//		printf("%s%d\n", "1.cost b :", data->cost_b_to_top);
		while (abs(data->cost_a_to_top) + abs(data->cost_b_to_top) != 0)
		{
//			printf("%s%d\n", "0.cost a :", data->cost_a_to_top);
//			printf("%s%d\n", "0.cost b :", data->cost_b_to_top);
//			stacks_visu(data);
			if (data->cost_a_to_top > 0 && data->cost_b_to_top > 0)
			{
//				printf("%s%d\n", "3.cost a :", data->cost_a_to_top);
//				printf("%s%d\n", "3.cost b :", data->cost_b_to_top);
				rotate_both_to_last(data);
				data->cost_a_to_top -= 1;
				data->cost_b_to_top -= 1;
			}
			else if (data->cost_a_to_top < 0 && data->cost_b_to_top < 0)
			{
//				printf("%s%d\n", "2.cost a :", data->cost_a_to_top);
//				printf("%s%d\n", "2.cost b :", data->cost_b_to_top);
				rotate_both_to_first(data);
				data->cost_a_to_top += 1;
				data->cost_b_to_top += 1;
			}
			else if (data->cost_a_to_top < 0 && data->cost_b_to_top == 0)
			{
//				printf("%s%d\n", "5.cost a :", data->cost_a_to_top);
//				printf("%s%d\n", "5.cost b :", data->cost_b_to_top);
				rotate_to_first_a(data);
				data->cost_a_to_top += 1;
			}
			else if (data->cost_b_to_top > 0 && data->cost_a_to_top == 0)
			{
//				printf("%s%d\n", "6.cost a :", data->cost_a_to_top);
//				printf("%s%d\n", "6.cost b :", data->cost_b_to_top);
				rotate_to_last_b(data);
				data->cost_b_to_top -= 1;
			}
			else if (data->cost_a_to_top > 0 && data->cost_b_to_top == 0)
			{
//				printf("%s%d\n", "4.cost a :", data->cost_a_to_top);
//				printf("%s%d\n", "4.cost b :", data->cost_b_to_top);
				rotate_to_last_a(data);
				data->cost_a_to_top -= 1;
			}
			else
			{
//				printf("%s%d\n", "7.cost a :", data->cost_a_to_top);
//				printf("%s%d\n", "7.cost b :", data->cost_b_to_top);
				rotate_to_first_b(data);
				data->cost_b_to_top += 1;
			}
//			exit (0);
		}
//		stacks_visu(data);
		check_order_a(data);
		is_min_a(data);
		is_max_b(data);
		if (data->is_in_order_a == 1 && data->is_min_a > data->is_max_b)
			push_to_a(data);
		check_qty_stack_b(data);
	}
//	stacks_visu(data);
//	printf("%s\n", "bye bye");
	check_order_a(data);
	if (data->is_in_order_a == 1 && data->moves > 0)
		return ;
}
	
// 	while (data->qty_stack_a > 3)
// 	{
// 		x = 0;
// 		while (data->stack_a[x] == 0)
// 			x++;
			
// //		position_in_a(data);
// 		data->pivot = (data->qty_stack_a / 2 + x);
// 		check_order_a(data);
// 		check_qty_stack_b(data);
// 		if (data->is_in_order_a == 1 && data->qty_stack_b > 0)
// 			break ;
// 		if (data->stack_a[x] > data->stack_a[data->index_max - 1]
// 			&& data->stack_a[x + 1] > data->stack_a[data->index_max - 1]
// 			&& data->stack_a[data->index_max - 1] <= data->pivot - 1)
// 				rotate_to_first_a(data);
// 		if (data->stack_a[x] > data->pivot - 1)
// 			rotate_to_last_a(data);
// 		else if (data->stack_a[x] <= data->pivot - 1)
// 			push_to_b(data);
// 		x = 0;
// 		while (data->stack_b[x] == 0)
// 			x++;
// 		if (data->stack_b[x] < data->index_max / 3
// 			&& data->stack_b[x] < data->stack_b[x + 1])
// 		{
// 			x = 0;
// 			while (data->stack_a[x] == 0)
// 				x++;
// 			data->pivot = (data->qty_stack_a / 2 + x);
// 			if (data->stack_a[x] > data->pivot - 1)
// 				rotate_both_to_last(data);
// 			else
// 				rotate_to_last_b(data);
// 		}
// 		else if (data->stack_b[x] < data->stack_b[x + 1])
// 			swap_top_b(data);
// 		check_qty_stack_a(data);
// 	}
	
// 	sort_3_init(data);
// 	check_qty_stack_b(data);
// 	while (data->qty_stack_b > 0)
// 	{
// 		check_qty_stack_a(data);
// 		check_order_a(data);
// 		is_min_a(data);
// 		if (data->is_in_order_a == 1)
// 			data->cost_a_to_top = 0;
// 		else if (data->min_a_pos
// 			<= (data->index_max - (data->qty_stack_a / 2) - 1))
// 				data->cost_a_to_top = data->min_a_pos
// 				- ((data->index_max - 1) - (data->qty_stack_a - 1));
// 		else
// 			data->cost_a_to_top = data->min_a_pos - (data->index_max - 1);
// 		check_qty_stack_b(data);
// 		check_reverse_order_b(data);
// 		is_max_b(data);
// 		if (data->is_in_order_b == -2)
// 			data->cost_b_to_top = 0;
// 		else if (data->max_b_pos
// 			<= (data->index_max - (data->qty_stack_b / 2) - 1))
// 				data->cost_b_to_top = data->max_b_pos
// 				- ((data->index_max - 1) - (data->qty_stack_b - 1));
// 		else
// 			data->cost_b_to_top = data->max_b_pos - (data->index_max);
// 		while (abs(data->cost_a_to_top) + abs(data->cost_b_to_top) != 0)
// 		{
// 			if (data->cost_a_to_top < 0 && data->cost_b_to_top < 0)
// 			{
// 				rotate_both_to_first(data);
// 				data->cost_a_to_top += 1;
// 				data->cost_b_to_top += 1;
// 			}
// 			else if (data->cost_a_to_top > 0 && data->cost_b_to_top > 0)
// 			{
// 				rotate_both_to_last(data);
// 				data->cost_a_to_top -= 1;
// 				data->cost_b_to_top -= 1;
// 			}
// 			else if (data->cost_a_to_top > 0 && data->cost_b_to_top == 0)
// 			{
// 				rotate_to_last_a(data);
// 				data->cost_a_to_top -= 1;
// 			}
// 			else if (data->cost_a_to_top < 0 && data->cost_b_to_top == 0)
// 			{
// 				rotate_to_first_a(data);
// 				data->cost_a_to_top += 1;
// 			}
// 			else if (data->cost_b_to_top > 0 && data->cost_a_to_top == 0)
// 			{
// 				rotate_to_last_b(data);
// 				data->cost_b_to_top -= 1;
// 			}
// 			else
// 			{
// 				rotate_to_first_b(data);
// 				data->cost_b_to_top += 1;
// 			}
// 		}
// 		push_to_a(data);
// 		check_qty_stack_b(data);
// 	}
// 	check_order_a(data);
// 	if (data->is_in_order_a == 1 && data->moves > 0)
// 		return ;
// }

void	sort_500(t_vault *data)
{
	unsigned int	round;
	unsigned int	x;
	unsigned int	y;
	unsigned int	value;

	round = 0;
	data->max_bits = 0;
	while (((data->index_max - 1) >> data->max_bits) != 0)
		data->max_bits++;
	while (round < data->max_bits)
	{
		y = 0;
		while (y < data->index_max)
		{
			x = 0;
			while (data->stack_a[x] == 0)
				x++;
			value = data->stack_a[x] >> round;
			if ((value & 1) == 1)
			{
				rotate_to_last_a(data);
				check_order_a(data);
			}
			else if (data->is_in_order_a != 1)
				push_to_b(data);
			y++;
		}
		check_qty_stack_b(data);
		while (data->qty_stack_b > 0)
		{
			push_to_a(data);
			check_qty_stack_b(data);
		}
		round++;
	}
}
