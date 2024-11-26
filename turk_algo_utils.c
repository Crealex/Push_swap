/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:27:50 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/26 22:14:31 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		show_biggest(t_stack *stack)
{
	int	biggest_temp;
	int i;
	t_stack *temp;

	temp = copy_stack_content(stack);
	temp = goto_head(temp);
	biggest_temp = temp->content;
	i = 0;
	while (len_stack(temp) >= (i + 1))
	{
		if (temp->content > biggest_temp)
			biggest_temp = temp->content;
		temp = shadow_rotate(temp);
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
	t_stack *temp;

	count = 0;
	temp = copy_stack_content(stack);
	while (temp)
	{
		if (temp->content == target)
		{
			free_stack_copy(temp);
			return (count);
		}
		temp = shadow_rotate(temp);
		count++;
	}
	free_stack_copy(temp);
	return (0);
}

int		count_rev_rot(t_stack *stack, int  target)
{
	int count;
	t_stack *temp;

	count = 0;
	temp = copy_stack_content(stack);
	while (temp)
	{
		if (temp->content == target)
		{
			free_stack_copy(temp);
			return (count);
		}
		temp = shadow_reverse_rotate(temp);
		count++;
	}
	free_stack_copy(temp);
	return (0);
}
