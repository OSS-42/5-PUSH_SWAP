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
*/

void	errors(t_vault *data) // a revoir
{
	if (data->error_code == 0)
		return ;
	else if (data->error_code == 1)
		printf("%s\n%s\n", "Error", "Paramètres non valides");
	else if (data->error_code == 2)
		printf("%s\n%s\n", "Error", "Il y a des doublons");
	else if (data->error_code == 3)
		printf("%s\n%s\n", "Error", "Paramètres en dehors des limites de INT");
	exit (0);
}

void	check_index(t_vault *data) // pour debug
{
	unsigned int	boucle;

	boucle = 0;
	while (boucle < data->nbr_args)
	{
		printf("%s%d%s%d%s%ld\n", "stack_a#", boucle, " : ", data->stack_a[boucle], " - arg = ", data->args_int[boucle]);
		boucle++;
	}
	printf("%s\n", "rendu la, on peut commencer le triage !");
}

void	stacks_visu(t_vault *data) // pour debug
{
	unsigned int	x;

	x = 0;
	printf("%s%s%s\n", "A", "	", "B");
	while (x < data->index_max)
	{
		printf("%d%s%d\n", data->stack_a[x], "	", data->stack_b[x]);
		x++;
	}
	printf("%s%d\n", "moves qty = ", data->moves);
	return ;
}

void	check_difficulty(t_vault *data)
{
	unsigned int	x;

	x = 0;
	data->difficulty = 0;
	while (x < data->index_max)
	{
		if (data->stack_a[x] > data->stack_a[x + 1])
			data->difficulty++;
		x++;
	}
}