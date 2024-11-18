/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:59:43 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/18 22:14:41 by alexandre        ###   ########.fr       */
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
		return (1);
	}
	//stack_b = calloc(sizeof(t_stack), 1);
	stack_a = parsing(argc, argv);
	if (!stack_a)
	{
		ft_printf(RED"Erreur, arguments invalide\n"END);
		free(stack_a);
		free(stack_b);
		return (1);
	}
	//ft_printf(YELLOW"-----DEBUT-----\n\n");
	//read_stack(stack_a, stack_b);
	//move_teser(stack_a, stack_b);
	bignum_algo(&stack_a, &stack_b);
	//dirty_algo(&stack_a, &stack_b);
	//ft_printf(YELLOW"-----FINAL-----\n\n");
	//read_stack(stack_a, stack_b);
}
