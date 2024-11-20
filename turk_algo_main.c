/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:32:40 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/20 15:26:17 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	put_in_a(t_stack **stack_a, t_stack **stack_b)
{
	//1. Trouver ou placer l' element.
	//2. move_stack la stack A pour la mettre bien.
	//3. push dans la stack A
} */

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_target	*target;
	t_stack		*temp_a;
	//t_stack		*temp_b;

	temp_a = *stack_a;
	if (is_sorted(*stack_a))
		exit(EXIT_SUCCESS);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	while (temp_a)
	{
		if (len_stack(*stack_a) <= 3)
		{
			ft_printf(RED"test\n"END);
			little_sort(stack_a, 'a');
			break ;
		}
		target = find_choice(*stack_a, *stack_b);
		exec_choice(stack_a, stack_b, target);
		temp_a = temp_a->next;
	}
	/* temp_b = *stack_b;
	while (temp_b)
	{
		put_in_a(stack_a, stack_b);
	} */
}
