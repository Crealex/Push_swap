/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:32:40 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/19 21:47:47 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_target	*target;
	t_stack		*temp_a;
	t_stack		*temp_b;

	temp_a = *stack_a;
	while (temp_a)
	{
		if (len_stack(*stack_a) <= 3)
		{
			little_sort(stack_a, 'a');
			break ;
		}
		target = find_choice(*stack_a, *stack_b);
		exec_choice(stack_a, stack_b, target);
		temp_a = temp_a->next;
	}
	temp_b = *stack_b;
	while (temp_b)
	{
		//remettre bien dans stack A (réfléchir a ce qui risque de rester dans a avant de tout renvoyer)
	}
}
