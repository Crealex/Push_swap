/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_chained.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:10:42 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/08 16:21:58 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack *stack)
{
	t_stack	*temp;

	if (stack->content && stack->next)
	{
		temp = stack;
		stack = stack->next;
		stack->next = temp;
	}
	return (stack);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = (*stack_a)->next;
	(*stack_b)->content = (int)malloc(sizeof(int));
	if (*stack_b)
	{
		(*stack_a)->content = (*stack_b)->content;
		(*stack_a)->next = temp;
		*stack_b = (*stack_b)->next;
	}
	return ;
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_b;
	if (*stack_a)
	{
		*stack_b = *stack_a;
		(*stack_b)->next = temp;
		*stack_a = (*stack_a)->next;
	}
	return ;
}

t_stack	*rotate(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*new_head;

	if (!stack || !stack->next)
		return (stack);
	temp = stack;
	new_head = stack->next;
	while (stack->next)
	{
		stack = stack->next;
	}
	temp->next = NULL;
	stack->next = temp;
	return (new_head);
}

t_stack	*reverse_rotate(t_stack *stack)
{
	t_stack	*new_second;
	t_stack	*new_last;
	t_stack	*new_head;

	new_second = stack;
	while (stack->next->next)
	{
		stack = stack->next;
	}
	new_last = stack;
	new_head = stack->next;
	new_head->next = new_second;
	new_last->next = NULL;
	return (new_head);
}
