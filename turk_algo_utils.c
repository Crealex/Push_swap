/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:27:50 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/19 18:43:09 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*show_biggest(t_stack *stack)
{
	t_stack	*biggest_temp;

	biggest_temp = stack;
	while (stack)
	{
		if (stack->content > biggest_temp->content)
			biggest_temp = stack;
		stack = stack->next;
	}
	return (biggest_temp);
}

void	shadow_rotate(t_stack **stack)
{
	int		temp;

	if (!*stack)
		return ;
	temp = (*stack)->content;
	while((*stack)->next)
	{
		(*stack) = (*stack)->next;
		(*stack)->prev->content = (*stack)->content;
	}
	(*stack)->content = temp;
	*stack = goto_head(*stack);
}

void	shadow_reverse_rotate(t_stack **stack)
{
	int old_last;

	if (!*stack)
		return;
	while ((*stack)->next)
		*stack = (*stack)->next;
	old_last = (*stack)->content;
	while((*stack)->prev)
	{
		(*stack)->content = (*stack)->prev->content;
		*stack = (*stack)->prev;
	}
	(*stack)->content = old_last;
}

int		count_rot(t_stack *stack, int target)
{
	t_stack *temp;
	int count;

	temp = stack;
	count = 0;
	while (temp)
	{
		if (temp->content == target)
			return (count);
		shadow_rotate(temp);
	}
	return (NULL);
}

int		count_rev_rot(t_stack *stack,int  target)
{
	t_stack *temp;
	int count;

	temp = stack;
	count = 0;
	while (temp)
	{
		if (temp->content == target)
			return (count);
		shadow_reverse_rotate(temp);
	}
	return (NULL);
}
