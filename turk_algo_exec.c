/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:52:59 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/20 15:52:43 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack(t_stack **stack, int target, char c)
{
	int choice;
	t_stack *temp;

	temp = *stack;
	ft_printf("stack : %d\n", (*stack)->content);
	choice = cost_compare(temp, target);
	ft_printf("stack : %d\n", (*stack)->content);
	ft_printf("target : %d\n", target);
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
