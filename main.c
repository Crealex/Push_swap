/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:59:43 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/14 17:20:26 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		ft_printf(RED"Erreur, pas assez d'arguments\n"END);
		return (1);
	}
	stack_b = calloc(sizeof(t_stack), 1);
	stack_a = parsing(argc, argv);
	if (!stack_a)
	{
		ft_printf(RED"Erreur, arguments invalide\n"END);
		return (1);
	}
	read_stack(stack_a, stack_b);
}
