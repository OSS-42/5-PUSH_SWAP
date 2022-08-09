/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 08:44:26 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/09 17:48:30 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	from_a_to_i(t_vault *data)
{
	unsigned int	x;

	x = 0;
	while (x < data->nbr_args)
	{
		*data->args[x] = ft_atoi(data->args[x]);
		printf("%s%x : %u\n", "arg#", x, *data->args[x]);
		x++;
	}
// erreur avec ./push_swap "1 3 4 -2" et sans quotes.
}

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
				data->error_code = 2;
			y++;
		}
		x++;
	}
	errors(data);
	return ;
}

static int	check_args(t_vault *data)
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
				data->error_code = 1;
			y++;
		}
		x++;
	}
	errors(data);
	from_a_to_i(data);
	if (data->nbr_args == 1)
// return a revoir
		return ((int)data->args[1]);
	if (data->nbr_args > 1)
		check_doubles(data);
	return (0);
}

static int	quotes_to_args(t_vault *data, char **argv)
{
	int	x;

	x = 0;
	data->args = ft_split(argv[1], ' ');
	while (data->args[x++])
		data->nbr_args++;
	check_args(data);
// erreur avec ./push_swap "1 3 4 -2"
	errors(data);
//	from_a_to_i(data);
	if (data->nbr_args == 1)
		return (*data->args[1]);
	return (0);
}

/*	
	trouver le nombre le plus petits de coups pour trier A.
	tips :
	par groupes
	B trié du plus grand au plus petit
	A trié du plus petit au plus grand
*/

int	main(int argc, char **argv)
{
	t_vault	data;

	data.error_code = 0;
	data.nbr_args = 0;
	if (argc == 1)
		return (0);
	if (!ft_strchr(argv[1], ' ') || argc > 2)
	{
		data.args = malloc(sizeof(char *) * argc);
		data.args = &argv[1];
		data.nbr_args = argc - 1;
		printf("%s %u\n", "1.nbr args :", data.nbr_args);
		check_args(&data);
	}
	else 
	{
//		data.args = &argv[1];
		quotes_to_args(&data, argv);
	}
	return (0);
}

