/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:27:50 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/24 13:09:09 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		show_biggest(t_stack *stack)
{
	int	biggest_temp;
	int i;
	stack = goto_head(stack);
	biggest_temp = stack->content;
	i = 0;
	while (len_stack(stack) >= (i + 1))
	{
		if (stack->content > biggest_temp)
			biggest_temp = stack->content;
		stack = shadow_rotate(stack);
		i++;
	}
	return (biggest_temp);
}

t_stack	*shadow_rotate(t_stack *stack)
{
	int		num;
	t_stack *temp;

	if (!stack)
		return (NULL);
	temp = stack;
	num = (temp)->content;
	while((temp)->next)
	{
		(temp) = (temp)->next;
		(temp)->prev->content = (temp)->content;
	}
	(temp)->content = num;
	temp = goto_head(temp);
	return (temp);
}

t_stack	*shadow_reverse_rotate(t_stack *stack)
{
	int old_last;
	t_stack *temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while ((temp)->next)
		temp = temp->next;
	old_last = (temp)->content;
	while((temp)->prev)
	{
		(temp)->content = (temp)->prev->content;
		temp = (temp)->prev;
	}
	(temp)->content = old_last;
	return (temp);
}

int		count_rot(t_stack *stack, int target)
{
	int count;

	count = 0;
	while (stack)
	{
		if (stack->content == target)
			return (count);
		stack = shadow_rotate(stack);
		count++;
	}
	return (0);
}

int		count_rev_rot(t_stack *stack,int  target)
{
	int count;

	count = 0;
	while (stack)
	{
		if (stack->content == target)
		{
			return (count);
		}
		stack = shadow_reverse_rotate(stack);
		count++;
	}
	return (0);
}
