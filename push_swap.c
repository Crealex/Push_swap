/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:25:47 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/11 17:57:48 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_phase(t_stack *stack_a, t_stack *stack_b)
{
	//premiere etape :
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	if (stack_a->content > stack_b->content)
	{
		if (stack_b->content > stack_b->next->content)
			push_b(stack_a, stack_b);
	}

	// insertion d'un nombreau bonne endroit de la satck_b
	while (1)
	{
		if (stack_a->content < stack_b->content && stack_a->content > stack_b->next->content)
		{
			stack_b = rotate(stack_b);
			push_b(stack_a, stack_b);
			break ;
		}
		stack_b = rotate(stack_b);
	}
}
