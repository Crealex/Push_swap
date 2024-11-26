/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:25:47 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/26 15:34:18 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
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
		ft_putendl_fd(RED"Erreur, argument(s) invalide(s)\n"END, 2);
		return (1);
	}
	//ft_printf("--------DEBUT-------");
	//read_stack(stack_a, stack_b);
	if (len_stack(stack_a) == 3)
		little_sort(&stack_a, 'a');
	else
		turk_sort(&stack_a, &stack_b);
	//bignum_algo(&stack_a, &stack_b);
	//ft_printf(YELLOW"-----FINAL-----\n"END);
	//read_stack(stack_a, stack_b);
	if (stack_a)
		free_stack_copy(stack_a);
	if (stack_b)
		free_stack_copy(stack_b);
	return (0);
}
