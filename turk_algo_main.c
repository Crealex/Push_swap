/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:32:40 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/20 17:13:42 by alexandre        ###   ########.fr       */
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

	temp_a = copy_stack_content(*stack_a);
	if (is_sorted(*stack_a))
	{
		free_stack_copy(temp_a);
		exit (EXIT_SUCCESS);
	}
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	while (temp_a)
	{
		ft_printf("longueur stack a : %d\n",len_stack(*stack_a));
		if (len_stack(*stack_a) <= 3)
		{
			little_sort(stack_a, 'a');
			break ;
		}
		target = find_choice(*stack_a, *stack_b);
		if (!target)
		{
			free_stack_copy(temp_a);
			return ;
		}
		exec_choice(stack_a, stack_b, target);
		temp_a = temp_a->next;
	}
	temp_a = goto_head(temp_a);
	free_stack_copy(temp_a);
	/* temp_b = *stack_b;
	while (temp_b)
	{
		put_in_a(stack_a, stack_b);
	} */
}
