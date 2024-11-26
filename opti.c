/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:18:13 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/26 14:23:48 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int cost_choice(t_stack *stack, int target)
{
	int count;
	int len;

	len = len_stack(stack);
	count = count_rot(stack, target);
	if (count > (len / 2))
		return (-1);
	else
		return (count);
}

int	find_target_v2(int current, t_stack *stack)
{
	t_stack	*temp;
	int		num;

	if (!stack)
		return (0);
	temp = copy_stack_content(stack);
	while (temp->next)
	{
		if ((temp->content > current && temp->next->content < current))
		{
			num = temp->next->content;
			free_stack_copy(goto_head(temp));
			return (num);
		}
		temp = temp->next;
	}
	temp = shadow_reverse_rotate(temp);
	if (temp->content > current && temp->next->content < current)
	{
			num = temp->next->content;
			free_stack_copy(goto_head(temp));
			return (num);
	}
	free_stack_copy(goto_head(temp));
	return (show_biggest(stack));
}