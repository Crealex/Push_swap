/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_chained.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:07:05 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/17 21:37:42 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack *stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !stack->next)
		return (stack);
	first = stack;
	second = stack->next;
	first->next = second->next;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	return (second);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_b)
		return ;
	if (!*stack_a)
	{
		*stack_a = malloc(sizeof(t_list) * 1);
		(*stack_a)->content = (*stack_b)->content;
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
		return ;
	}
	temp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	(*stack_a)->next = temp;
	(*stack_a)->prev = NULL;
	if (temp)
		temp->prev = *stack_a;
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_a)
		return ;
	if (!*stack_b)
	{
		*stack_b = malloc(sizeof(t_list) * 1);
		(*stack_b)->content = (*stack_a)->content;
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
		return ;
	}
	temp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	(*stack_b)->next = temp;
	(*stack_b)->prev = NULL;
	if (temp)
		temp->prev = *stack_b;
}

void	rotate(t_stack **stack)
{
	t_stack	*old_first;
	t_stack	*new_first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	old_first = *stack;
	new_first = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	new_first->prev = NULL;
	old_first->prev = last;
	old_first->next = NULL;
	last->next = old_first;
	*stack = new_first;
	return ;
}

t_stack	*reverse_rotate(t_stack *stack)
{
	t_stack	*new_last;
	t_stack	*old_last;

	if (!stack || !stack->next)
		return (stack);
	new_last = stack;
	while (new_last->next->next)
		new_last = new_last->next;
	old_last = new_last->next;
	old_last->prev = NULL;
	old_last->next = stack;
	stack->prev = old_last;
	new_last->next = NULL;
	return (old_last);
}
