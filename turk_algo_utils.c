/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:27:50 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/20 16:18:53 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*show_biggest(t_stack *stack)
{
	t_stack	*biggest_temp;
	int i;

	biggest_temp = stack;
	i = 0;
	while (len_stack(stack) <= i)
	{
		if (stack->content > biggest_temp->content) // a modifier, il faut faire des rotates a la place !!!
			biggest_temp = stack;
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
	t_stack *temp;
	int count;

	temp = stack;
	count = 0;
	while (temp)
	{
		if (temp->content == target)
			return (count);
		temp = shadow_rotate(temp);
		count++;
	}
	return (0);
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
		temp = shadow_reverse_rotate(temp);
		count++;
	}
	return (0);
}
