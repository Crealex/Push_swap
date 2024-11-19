/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:52:59 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/19 21:31:47 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack(t_stack **stack, int target, char c)
{
	int choice;

	choice = cost_compare(*stack, target);
	if (choice > 0)
	{
		while (*stack)
		{
			if ((*stack)->content == target)
				return ;
			reverse_rotate(stack, c);
		}
	}
	else
	{
		while (*stack)
		{
			if ((*stack)->content == target)
				return ;
			rotate(stack, c);
		}
	}
}

void	exec_choice(t_stack **stack_a, t_stack **stack_b, t_target *choice)
{
	move_stack(stack_a, choice->target_a, 'a');
	move_stack(stack_b, choice->target_b, 'b');
	push_b(stack_a, stack_b);
}