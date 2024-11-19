/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:13:38 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/19 13:33:52 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_index(t_stack *stack)
{
	int i;
	t_stack *current;

	current = stack;
	i = 0;
	while (current)
	{
		current->index = i;
		i++;
		current = current->next;
	}
}

void	update_two_index(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return;
	update_index(stack_a);
	update_index(stack_b);

}