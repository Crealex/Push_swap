/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:52:59 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/27 13:38:12 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_stack(t_stack **stack, int target,int choice, char c)
{
	if (choice == -1)
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

void	double_move_stack(t_stack **stack_a, t_stack **stack_b, t_target *choice)
{
	if (choice->move_a == -1)
	{
		while (*stack_a && *stack_b)
		{
			if ((*stack_a)->content == choice->target_a || (*stack_b)->content == choice->target_b)
				return ;
			double_reverse_rotate(stack_a, stack_b);
		}
	}
	else
	{
		while (*stack_a && *stack_b)
		{
			if ((*stack_a)->content == choice->target_a || (*stack_b)->content == choice->target_b)
				return ;
			double_rotate(stack_a, stack_b);
		}
	}
}

void	exec_choice(t_stack **stack_a, t_stack **stack_b, t_target *choice)
{
	if (choice->move_a >= 0)
		choice->move_a = 1;
	if (choice->move_b >= 0)
		choice->move_b = 1;
	if (choice->move_a == choice->move_b)
	{
		double_move_stack(stack_a, stack_b, choice);
	}
	if ((*stack_a)->content != choice->target_a)
		move_stack(stack_a, choice->target_a, choice->move_a, 'a');
	if ((*stack_b)->content != choice->target_b)
		move_stack(stack_b, choice->target_b, choice->move_b, 'b');
	free(choice);
	//ft_printf("smallest : %d\n", is_smallest(*stack_b, (*stack_a)->content));
	if (is_smallest(*stack_b, (*stack_a)->content))
	{
		push_b(stack_a, stack_b);
		reverse_rotate(stack_b, 'b');
	}
	else
		push_b(stack_a, stack_b);
}
