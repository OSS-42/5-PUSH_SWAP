/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 08:44:26 by ewurstei          #+#    #+#             */
/*   Updated: 2022/09/15 11:23:10 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
min = -2147483648 ; max = 2147483647
*/

void	saving_args(t_vault *data, int argc, char **argv)
{
	int	x;

	if (!ft_strchr(argv[1], ' ') || argc > 2)
	{
		data->args = malloc(sizeof(char *) * argc); // a free lorsque pas quotes
		if (!data->args)
			return ;
		data->args = &argv[1];
		data->args[argc] = "\0";
		x = 0;
//		while (x++ < argc)
//			data->args[x] = ft_calloc(sizeof(long), 1);
		data->nbr_args = argc - 1;
		check_args(data);
	}
	else
		quotes_to_args(data, argv);
}

void	check_doubles(t_vault *data)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < data->nbr_args)
	{
		y = x + 1;
		while (y < data->nbr_args)
		{
			if (data->args_int[x] == data->args_int[y])
				data->error_code = 2;
			y++;
		}
		x++;
	}
	errors(data);
	return ;
}

int	check_args(t_vault *data)
{
	unsigned int	x;
	int				y;

	x = 0;
	while (x < data->nbr_args)
	{
		y = 0;
		while (data->args[x][y])
		{
			if (data->args[x][y] == 43 || data->args[x][y] == 45)
				if (data->args[x][y + 1] < 48 || data->args[x][y + 1] > 57)
					data->error_code = 1;
			if ((data->args[x][y] < 48 || data->args[x][y] > 57)
				&& data->args[x][y] != 43 && data->args[x][y] != 45)
				data->error_code = 1;
			y++;
		}
		x++;
	}
	errors(data);
	return (0);
}

int	quotes_to_args(t_vault *data, char **argv)
{
	int	x;

	x = 0;
	data->args = ft_split(argv[1], ' ');
	while (data->args[x++])
		data->nbr_args++;
	check_args(data);
	errors(data);
	if (data->nbr_args == 1)
		return (*data->args[1]);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vault	data;

	data.error_code = 0;
	data.nbr_args = 0;
	data.nbr_argc = argc;
	if (argc == 1 || !*argv[1])
		return (0);
	saving_args(&data, argc, argv);
	from_a_to_long(&data);
	if (data.nbr_args == 1)
		return (data.args_int[1]);
	if (data.nbr_args > 1)
		check_doubles(&data);
	indexing_numbers(&data);
//	free_dbl_ptr((void **)data.args);
	free(data.args_int);
	return (0);
}
