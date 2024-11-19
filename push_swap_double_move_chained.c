/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_double_move_chained.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:45:11 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/19 14:18:58 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	temp;

	ft_printf("ss\n");
	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	temp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = temp;
	temp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = temp;
	update_two_index(*stack_a, *stack_b);
}

void	double_rotate(t_stack **stack_a, t_stack **stack_b)
{
	int	temp;

	ft_printf("rr\n");
	if (!*stack_a || !*stack_b)
		return;
	temp = (*stack_a)->content;
	while((*stack_a)->next)
	{
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->prev->content = (*stack_a)->content;
	}
	(*stack_a)->content = temp;
	*stack_a = goto_head(*stack_a);
	temp = (*stack_b)->content;
	while((*stack_b)->next)
	{
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->prev->content = (*stack_b)->content;
	}
	(*stack_b)->content = temp;
	*stack_b = goto_head(*stack_b);
	update_two_index(*stack_a, *stack_b);
}

void	double_reverse_rotate(t_stack **stack_a, t_stack **stack_b)
{
	int old_last;

	ft_printf("rrr\n");
	if (!*stack_a || !*stack_b)
		return ;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	old_last = (*stack_a)->content;
	while((*stack_a)->prev)
	{
		(*stack_a)->content = (*stack_a)->prev->content;
		*stack_a = (*stack_a)->prev;
	}
	(*stack_a)->content = old_last;
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	old_last = (*stack_b)->content;
	while((*stack_b)->prev)
	{
		(*stack_b)->content = (*stack_b)->prev->content;
		*stack_b = (*stack_b)->prev;
	}
	(*stack_b)->content = old_last;
	update_two_index(*stack_a, *stack_b);
}
