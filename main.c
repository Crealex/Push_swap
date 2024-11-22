/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:59:43 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/21 17:46:01 by alexandre        ###   ########.fr       */
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
	stack_a = parsing(argc, argv);
	if (!stack_a)
	{
		ft_putendl_fd(RED"Erreur, arguments invalide\n"END, 2);
		return (1);
	}
	//ft_printf(YELLOW"-----DEBUT-----\n\n");
	//update_index(stack_a);
	read_stack(stack_a, stack_b);
	//move_teser(stack_a, stack_b);
	turk_sort(&stack_a, &stack_b);
	//bignum_algo(&stack_a, &stack_b);
	//dirty_algo(&stack_a, &stack_b);
	//little_sort(&stack_a, 'a');
	//ft_printf(YELLOW"-----FINAL-----");
	read_stack(stack_a, stack_b);
	free_stack_copy(stack_a);
	free_stack_copy(stack_b);
	return (0);
}
