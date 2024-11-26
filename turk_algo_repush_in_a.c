/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_repush_in_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:10:16 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/24 19:10:17 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_in_a(t_stack **stack_a, t_stack **stack_b, int limit)
{
	while(*stack_b && (*stack_b)->content > limit)
	{
		push_a(stack_a, stack_b);
	}
	return ;
}

void	move_stack_a(t_stack **stack, int target, char c)
{
		while (*stack)
		{
			if ((*stack)->content == target)
				return ;
			reverse_rotate(stack, c);
		}
}

void	repush_in_a(t_stack **stack_a, t_stack **stack_b)
{
	//0. Identifer la valeur des trois chiffre de a
	int smallest;
	int middle;
	int biggest;

	smallest = (*stack_a)->content;
	middle = (*stack_a)->next->content;
	biggest = (*stack_a)->next->next->content;
	//1. Mettre le premier de b au dessus de a(car avec une simple rotate il se mettra bien)
	//2. Temps que que b est plus grand que le plus grand de a continuer de push
	push_in_a(stack_a, stack_b, biggest);
	//3. Se mettre sur le plus grand des 3 de a
	move_stack_a(stack_a, biggest, 'a');
	//4. push jusq'a que b est plsu grande que le deuxieme plus grand.
	push_in_a(stack_a, stack_b, middle);
	//5. etc...
	move_stack_a(stack_a, middle, 'a');
	push_in_a(stack_a, stack_b, smallest);
	move_stack_a(stack_a, smallest, 'a');
	while (*stack_b)
		push_a(stack_a, stack_b);
	return ;
}
