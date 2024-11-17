/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:58:17 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/17 16:52:31 by alexandre        ###   ########.fr       */
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
	int		biggest_temp;
	t_stack	*temp;

	biggest_temp = (*stack)->content;
	temp = *stack;
	while (temp)
	{
		if (temp->content > biggest_temp)
			biggest_temp = temp->content;
		temp = temp->next;
	}
	while ((*stack)->content != biggest_temp)
		rotate(stack);
}

int		is_sorted(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}