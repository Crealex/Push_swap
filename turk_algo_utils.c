/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:27:50 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/27 10:30:03 by atomasi          ###   ########.fr       */
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
	free_stack_copy(temp);
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

int count_rot(t_stack *stack, int target)
{
	t_stack	*temp;
	int		count;

	if (!stack)
		return (0);
	temp = stack;
	count = 0;
	while (temp)
	{
		if (temp->content == target)
			return count;
		count++;
		temp = temp->next;
	}
return (0);
}

int count_rev_rot(t_stack *stack, int target)
{
	t_stack	*temp;
	int		size;
	int		target_pos;

	if (!stack)
		return (0);
	size = 0;
	target_pos = 0;
	temp = stack;
	while (temp)
	{
		if (temp->content == target)
			target_pos = size;
		size++;
		temp = temp->next;
	}
	if (target_pos > 0)
		return (size - target_pos);
	return (0);
}
