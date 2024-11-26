/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:18:13 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/26 14:23:48 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int cost_choice(t_stack *stack, int target)
{
	int count;
	int len;

	len = len_stack(stack);
	count = count_rot(stack, target);
	if (count > (len / 2))
		return (-1);
	else
		return (1);
}