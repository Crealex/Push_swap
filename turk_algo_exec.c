/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:52:59 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/19 19:26:09 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack(t_stack **stack, int target)
{
	// 1. Appeler cost_compare (et la mettre a un endroit plus logique au passage)
	// 2. Faire rotate ou reverse_rotate en fonction du resultat jusqu'a arrivé à choice->number
}

void	exec_choice(t_stack **stack_a, t_stack **stack_b, t_target *choice)
{
	move_stack(stack_a, choice->target_a);
	move_stack(stack_b, choice->target_b);
	push_b(stack_a, stack_b);
}
