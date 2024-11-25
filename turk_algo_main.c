/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:32:40 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/22 20:51:34 by alexandre        ###   ########.fr       */
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
	//t_stack *head;
	//t_stack		*temp_b;

	if (is_sorted(*stack_a))
	{
		exit (EXIT_SUCCESS);
	}
	push_b(stack_a, stack_b);
	if (len_stack(*stack_a) <= 3)
	{
		little_sort(stack_a, 'a');
		//truc a faire pour trier le dernier element !!!!
		exit (EXIT_SUCCESS);
	}
	push_b(stack_a, stack_b);
	temp_a = copy_stack_content(*stack_a);
	*stack_b = goto_head(*stack_b);
	if ((*stack_b)->content < (*stack_b)->next->content)
	{
		swap(stack_b, 'b');;
	}
	while (temp_a)
	{
		if (len_stack(*stack_a) <= 3)
		{
			little_sort(stack_a, 'a');
			break ;
		}
		target = find_choice(*stack_a, *stack_b);
		if (!target)
		{
			free_stack_copy(goto_head(temp_a));
			return ;
		}
		exec_choice(stack_a, stack_b, target);
		temp_a = temp_a->next;
	}
	free_stack_copy(goto_head(temp_a));
	goto_biggest(stack_b, 'b');
	/* temp_b = *stack_b;
	while (temp_b)
	{
		put_in_a(stack_a, stack_b);
	} */
}
