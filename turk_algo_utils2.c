/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:23:16 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/20 16:22:56 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		cost_compare(t_stack *stack, int target)
{
	t_stack *temp;
	int count;
	int count_rev;

	temp = stack;
	count = count_rot(temp, target); // le probelme vient porbablement de là
	count_rev = count_rev_rot(temp, target);
	return (count - count_rev);
}