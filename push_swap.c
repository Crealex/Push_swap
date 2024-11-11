/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:25:47 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/11 21:24:08 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_phase(t_stack *stack_a, t_stack *stack_b) // nom de la fonction provisoire
{
	//premiere etape :
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);

	// insertion d'un nombre au bonne endroit de la satck_b
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
	// renvoie dans la stack_a
	while (stack_b)
	{
		push_a(stack_a, stack_b);
		stack_b = stack_b->next;
	}
	stack_b = goto_head(stack_b);

}
