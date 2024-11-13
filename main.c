/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:59:43 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/13 17:37:40 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int i;
	int content;
	t_stack *stack_a;
	t_stack *stack_a_temp;
	t_stack *stack_b;

	stack_b = NULL;
		if (argc < 2)
	{
		ft_printf("\033[0;31mErreur, pas assez d'arguments\n");
		return (1);
	}
	i = 1;
	// parsing
	content = ft_atoi(argv[i++]);
	stack_a = ft_lstnew_pimp(content);
	stack_b = calloc(sizeof(t_stack), 1);
	while(i < argc)
	{
		content = ft_atoi(argv[i]);
		stack_a_temp = ft_lstnew_pimp(content);
		ft_lstadd_back_pimp(&stack_a, stack_a_temp);
		i++;
	}
	//move_teser(stack_a, stack_b);
	first_phase(stack_a, stack_b);
}
