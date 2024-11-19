/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:23:11 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/19 16:29:44 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	little_sort(t_stack **stack, char c)
{
	if ((*stack)->content < (*stack)->next->content)
	{
		if ((*stack)->next->content < (*stack)->next->next->content)
			return ;
		else if ((*stack)->next->content > (*stack)->next->next->content
			&& (*stack)->content > (*stack)->next->next->content)
			reverse_rotate(stack, c);
		else if ((*stack)->next->content > (*stack)->next->next->content
			&& (*stack)->content < (*stack)->next->next->content)
		{
			swap(stack, c);
			rotate(stack, c);
		}
	}
	else if ((*stack)->next->content > (*stack)->next->next->content)
	{
		swap(stack, c);
		reverse_rotate(stack, c);
	}
	else if ((*stack)->next->content < (*stack)->next->next->content
		&& (*stack)->content > (*stack)->next->next->content)
		rotate(stack, c);
	else if ((*stack)->next->content < (*stack)->next->next->content
		&& (*stack)->content < (*stack)->next->next->content)
		swap(stack, c);
}
