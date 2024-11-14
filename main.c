/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:59:43 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/14 15:23:03 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int i;
	//int content;
	t_stack *stack_a;
	//t_stack *stack_a_temp;
	t_stack *stack_b;

	stack_b = NULL;
		if (argc < 2)
	{
		ft_printf("\033[0;31mErreur, pas assez d'arguments\n");
		return (1);
	}
	i = 1;
	// if fonction de check est mauvaise return 1 avec un mess d'erreur
	stack_b = calloc(sizeof(t_stack), 1);
	stack_a = parsing(argc, argv);
	if (!stack_a)
		return (NULL);
	read_stack(stack_a, stack_b);
	//move_teser(stack_a, stack_b);
	//first_phase(stack_a, stack_b);
}
