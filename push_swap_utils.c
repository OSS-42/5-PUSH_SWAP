/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:42:13 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/11 13:12:08 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
attention, Error à envoyer sur stdout et le reste sur stderr
Code 1 : Paramètres non valide
Code 2 : Doublons
Code 3 : Hors limites INT
Code 4 : Over 500 values - pas implémenté, car pas demandé
*/

void	errors(t_vault *data)
{
	if (data->error_code == 0)
		return ;
	else if (data->error_code == 1)
		write(2, "Error\n", 6);
	else if (data->error_code == 2)
	{
		write(2, "Error\n", 6);
		free (data->args_int);
	}
	else if (data->error_code == 3)
	{
		write(2, "Error\n", 6);
		free (data->args_int);
	}
	exit (0);
}

unsigned int	position_x_a(t_vault *data)
{
	unsigned int	x;

	x = 0;
	while (data->stack_a[x] == 0)
		x++;
	return (x);
}

/*void	stacks_visu(t_vault *data) // pour debug
{
	unsigned int	x;

	x = 0;
	printf("%s%d\n", "index_max = ", data->index_max);
	printf("%s%s%s\n", "A", "	", "B");
	while (x < data->index_max)
	{
		printf("%d%s%d\n", data->stack_a[x], "	", data->stack_b[x]);
		x++;
	}
	printf("%s%d\n", "moves qty = ", data->moves);
	return ;
}*/

/*void	check_index(t_vault *data) // pour debug
{
	unsigned int	boucle;

	boucle = 0;
	while (boucle < data->nbr_args)
	{
		printf("%s%d%s%d%s%ld\n", "stack_a#", boucle, " : ",
			data->stack_a[boucle], " - arg = ", data->args_int[boucle]);
		boucle++;
	}
	printf("%s\n", "rendu la, on peut commencer le triage !");
}*/