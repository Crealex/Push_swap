/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirty_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:53:10 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/16 22:23:53 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_in_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;

	temp_b = *stack_b;
	ft_printf(YELLOW"%d\n"END, (*stack_b)->content); // pour verif un truc
	while (temp_b)
	{
		if ((*stack_a)->content < temp_b->content && (*stack_a)->content > temp_b->next->content)
		{
			rotate(stack_b);
			push_b(stack_a, stack_b);
			read_stack(*stack_a, *stack_b); // pour verif un truc
			return ;
		}
		temp_b = temp_b->next;
	}
	if ((*stack_a)->content > (*stack_b)->content)
	{
		goto_biggest(stack_b);
		push_b(stack_a, stack_b);
	}
	else
	{
		goto_biggest(stack_b);
		push_b(stack_a, stack_b);
		rotate(stack_b);
	}
}

void	dirty_algo(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (is_sorted(*stack_a))
		return ;
	temp_a = *stack_a;
	temp_b = *stack_b;
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	while (temp_a)
	{
		insert_in_b(stack_a, stack_b);
	temp_a = *stack_a; // pas sur du truc
		temp_a = temp_a->next;
	}
	// renvoi dans la stack_a
	while (temp_b)
	{
		push_a(stack_a, stack_b);
		temp_b = temp_b->next;
	}
	*stack_b = goto_head(*stack_b);
	return ;
}
