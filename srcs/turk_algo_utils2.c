/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:23:16 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/27 13:38:31 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

t_stack		*shadow_goto_biggest(t_stack *stack)
{
	int	biggest_temp;
	int i;
	int len;

	stack = goto_head(stack);
	biggest_temp = stack->content;
	i = 0;
	len = len_stack(stack);
	while (len >= i)
	{
		if (stack->content > biggest_temp)
			biggest_temp = stack->content;
		else
			stack = shadow_rotate(stack);
		i++;
	}
	while ((stack)->content != biggest_temp)
		shadow_rotate(stack);
	return (stack);
}

int		show_smallest(t_stack *stack)
{
	int	smallest;
	int i;
	stack = goto_head(stack);
	smallest = stack->content;
	i = 0;
	while (len_stack(stack) >= (i + 1))
	{
		if (stack->content < smallest)
			smallest = stack->content;
		stack = shadow_rotate(stack);
		i++;
	}
	return (smallest);
}