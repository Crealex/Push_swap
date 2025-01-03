/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:59:43 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/22 21:10:13 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	old_main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	stack_a = parsing(argc, argv);
	if (!stack_a)
	{
		ft_putendl_fd(RED"Erreur, arguments invalide\n"END, 2);
		return (1);
	}
	read_stack(stack_a, stack_b);
	turk_sort(&stack_a, &stack_b);
	ft_printf(YELLOW"-----FINAL-----\n"END);
	read_stack(stack_a, stack_b);
	if (stack_a)
		free_stack_copy(stack_a);
	if (stack_b)
		free_stack_copy(stack_b);
	return (0);
}

	//move_teser(stack_a, stack_b);