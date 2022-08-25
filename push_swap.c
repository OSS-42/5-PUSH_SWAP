/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 08:44:26 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/11 13:11:55 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	from_a_to_long(t_vault *data)
{
	unsigned int	x;

	x = 0;
	data->args_int = malloc(sizeof(long *) * data->nbr_args);
	if (!data->args_int)
		return ;
	while (x < data->nbr_args)
	{
		printf("%s%x : %s\n", "avant arg#", x, data->args[x]);
		data->args_int[x] = ft_atolong(data->args[x]);
		printf("%s%x : %ld\n", "apres arg#", x, data->args_int[x]);
		if (data->args_int[x] > INT_MAX || data->args_int[x] < INT_MIN)
			data->error_code = 3;
		x++;
	}
	errors(data);
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
			if (data->args_int[x] == data->args_int[y])
				data->error_code = 2;
			y++;
		}
		x++;
	}
	if (data->nbr_args > 500)
		data->error_code = 4;
	errors(data);
	return ;
}

static int	check_args(t_vault *data)
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
	from_a_to_long(data);
	if (data->nbr_args == 1)
		return (data->args_int[1]);
	if (data->nbr_args > 1)
		check_doubles(data);
	return (0);
}

static int	quotes_to_args(t_vault *data, char **argv)
{
	int	x;

	x = 0;
	data->args = ft_split(argv[1], ' '); // a free lorsque quotes
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
	if (argc == 1 || !*argv[1])
		return (0);
	if (!ft_strchr(argv[1], ' ') || argc > 2)
	{
		data.args = malloc(sizeof(char *) * argc);  // a free lorsque pas quotes
		if (!data.args)
			return (0);
		data.args = &argv[1];
		data.nbr_args = argc - 1;
		printf("%s %u\n", "1.nbr args :", data.nbr_args);
		check_args(&data);
	}
	else
	{
		quotes_to_args(&data, argv);
	}
	printf("%s\n", "rendu-là, on peut commencer l'indexation !");
	indexing_numbers(&data);
	return (0);
}
