/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:23:16 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/19 21:23:54 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		cost_compare(t_stack *stack, int target)
{
	t_stack *temp;
	int count;
	int count_rev;

	count = count_rot(stack, target);
	count_rev = count_rev_rot(stack, target);
	return (count - count_rev);
}