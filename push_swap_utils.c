/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:58:17 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/15 16:48:03 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		len_stack(t_stack *stack)
{
	int i;

	i = 0;
	while (stack->prev)
	{
		stack = stack->prev;
	}
	while (stack->next)
	{
		i++;
		stack = stack->next;
	}
	i++;
	return (i);
}

t_stack	*goto_head(t_stack *stack)
{
	while (stack->prev)
	{
		stack = stack->prev;
	}
	return (stack);
}

void	goto_biggest(t_stack **stack)
{
	int	biggest_temp;

	biggest_temp = 0;
	while (*stack)
	{
		if ((*stack)->content > biggest_temp)
			biggest_temp = (*stack)->content;
		*stack = (*stack)->next;
	}
	*stack = goto_head(*stack);
	while (*stack)
	{
		if ((*stack)->content == biggest_temp)
			return;
		*stack = (*stack)->next;
	}
	return ;
}

int		is_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}