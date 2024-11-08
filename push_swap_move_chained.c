/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_chained.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:10:42 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/08 13:37:36 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap(t_list *stack)
{
	t_list	*temp;

	if (stack->content && stack->next)
	{
		temp = stack;
		stack = stack->next;
		stack->next = temp;
	}
	return (stack);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_a;
	if (*stack_b)
	{
		*stack_a = *stack_b;
		(*stack_a)->next = temp;
		*stack_b = (*stack_b)->next;
	}
	return ;
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_b;
	if (*stack_a)
	{
		*stack_b = *stack_a;
		(*stack_b)->next = temp;
		*stack_a = (*stack_a)->next;
	}
	return ;
}

t_list	*rotate(t_list *stack)
{
	t_list	*temp;
	t_list	*new_head;

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

t_list	*reverse_rotate(t_list *stack)
{
	t_list	*new_second;
	t_list	*new_last;
	t_list	*new_head;

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
