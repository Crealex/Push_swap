/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_repush_in_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:10:16 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/27 14:15:49 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_in_a(t_stack **stack_a, t_stack **stack_b, int limit)
{
	while (*stack_b && (*stack_b)->content > limit)
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
	int	smallest;
	int	middle;
	int	biggest;

	smallest = (*stack_a)->content;
	middle = (*stack_a)->next->content;
	biggest = (*stack_a)->next->next->content;
	push_in_a(stack_a, stack_b, biggest);
	move_stack_a(stack_a, biggest, 'a');
	push_in_a(stack_a, stack_b, middle);
	move_stack_a(stack_a, middle, 'a');
	push_in_a(stack_a, stack_b, smallest);
	move_stack_a(stack_a, smallest, 'a');
	while (*stack_b)
		push_a(stack_a, stack_b);
	return ;
}
