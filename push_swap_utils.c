/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:58:17 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/11 18:26:24 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		len_stack(t_stack *stack)
{
	int i;

	i = 0;
	while (stack->next)
	{
		i++;
		stack = stack->next;
	}
	i++;
	return (i);
}