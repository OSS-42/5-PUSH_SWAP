/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 08:44:26 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/04 16:10:35 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_doubles(t_vault *data)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < data->nbr_args)
	{
		y = x + 1;
		while (y < data->nbr_args)
		{
			if (strncmp(data->args[x], data->args[y], data->nbr_args) == 0)
				data->error_code = 4;
			y++;
		}
		x++;
	}
	errors(data);
	return ;
}

static void	check_args(t_vault *data)
{
	unsigned int	x;
	int	y;

	x = 0;
	while (x < data->nbr_args)
	{
		y = 0;
		while (data->args[x][y])
		{
			if ((data->args[x][y] < 48 || data->args[x][y] > 57)
				&& data->args[x][y] != 43 && data->args[x][y] != 45)
				data->error_code = 2;
			y++;
		}
		x++;
	}
	errors(data);
	check_doubles(data);
	return ;
}

static void	quotes_to_args(t_vault *data)
{
	data->args = ft_split(*data->args, ' ');
	while (data->args[data->nbr_args])
		data->nbr_args++;
	if (data->nbr_args == 1)
		data->error_code = 1;
	errors(data);
	return ;
}

/*	
	trouver le nombre le plus petits de coups pour trier A.
	tips :
	par groupe
	B trié du plus grand au plus petit
	A trié du plus petit au plus grand
*/

int	main(int argc, char **argv)
{
	t_vault	data;
	int		x;

	data.error_code = 0;
	data.nbr_args = 0;
	if (argc < 2)
		data.error_code = 1;
	errors(&data);
	if (argc == 2)
	{
		data.args = &argv[1];
		quotes_to_args(&data);
	}
	else
	{
		x = 1;
		data.args = malloc(sizeof(char *) * argc);
		while (x < argc)
		{
			data.args[x - 1] = argv[x];
			data.nbr_args++;
			x++;
		}
	}
	check_args(&data);
	return (0);
}

