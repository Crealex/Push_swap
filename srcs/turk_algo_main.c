/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:32:40 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/27 13:38:18 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_in_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*temp;
	t_target	*target;

	temp = copy_stack_content(*stack_a);
	while (temp)
	{
		if (len_stack(*stack_a) <= 3)
		{
			little_sort(stack_a, 'a');
			break ;
		}
		target = find_choice(*stack_a, *stack_b);
		if (!target)
		{
			free_stack_copy(goto_head(temp));
			return ;
		}
		exec_choice(stack_a, stack_b, target);
		temp = temp->next;
	}
	free_stack_copy(goto_head(temp));
	return ;
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
	{
		exit (EXIT_SUCCESS);
	}
	push_b(stack_a, stack_b);
	if (len_stack(*stack_a) <= 3)
	{
		little_sort(stack_a, 'a');
		repush_in_a(stack_a, stack_b);
		exit (EXIT_SUCCESS);
	}
	push_b(stack_a, stack_b);
	*stack_b = goto_head(*stack_b);
	if ((*stack_b)->content < (*stack_b)->next->content)
	{
		swap(stack_b, 'b');
	}
	push_in_b(stack_a, stack_b);
	goto_biggest(stack_b, 'b');
	repush_in_a(stack_a, stack_b);
}
