/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:23:16 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/22 21:00:16 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		cost_compare(t_stack *stack, int target)
{
	t_stack *temp;
	int count;
	int count_rev;

	temp = copy_stack_content(stack);
	if (!temp)
		return(0);
	count = count_rot(temp, target); // le probelme vient porbablement de là
	count_rev = count_rev_rot(temp, target);
	free_stack_copy(temp);
	return (count - count_rev);
}