/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:47:15 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/05 19:10:07 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*swap(int *stack)
{
	int temp;
	int i;
	i = 0;
	while (stack[i])
	{
		i++;
	}
	if (i >= 2)
	{
		temp = stack[0];
		stack[0] = stack[1];
		stack[1] = temp;
	}
	return (stack);
}

void	push_a(int **stack_a, int **stack_b)
{
	int ia;
	int ib;

	ia = 0;
	ib = 0;
	while (stack_a[ia])
		ia++;
	while (stack_b[ib])
		ib++;
	if (ib >= 1)
	{
		while (ia > 0)
		{
			stack_a[ia + 1] = stack_a[ia];
			ia--;
		}
		stack_a[0] = stack_b[0];
	}
}

void	push_b(int **stack_a, int **stack_b)
{
	int ia;
	int ib;

	ia = 0;
	ib = 0;
	while (stack_a[ia])
		ia++;
	while (stack_b[ib])
		ib++;
	if (ia >= 1)
	{
		while (ib > 0)
		{
			stack_b[ib + 1] = stack_b[ib];
			ib--;
		}
		stack_b[0] = stack_a[0];
	}
}

int		*rotate(int *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack[0];
	while (stack[i + 1])
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = temp;
	stack[i + 1] = NULL;
	return (stack);
}

int		*reverse_rotate(int *stack)
{
	int	i;
	int	temp;

	i = 0;
	while (stack[i])
		i++;
	temp = stack[i];
	stack[i + 1] = NULL;
	while ((i - 1) > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = temp;
	return (stack);
}