/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:32:30 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/19 10:29:24 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bignum_algo(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	while(*stack_a)
	{
		push_b(stack_a, stack_b);
	}
	while (*stack_b)
	{
		goto_biggest(stack_b, 'b');
		push_a(stack_a, stack_b);
	}
}
