/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:32:30 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/18 22:10:52 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bignum_algo(t_stack **stack_a, t_stack **stack_b)
{
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
