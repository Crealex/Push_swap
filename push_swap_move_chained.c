/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_chained.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:07:05 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/18 22:14:12 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack *stack, char c)
{
	t_stack	*first;
	t_stack	*second;
	print_move(c, 's');
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
	ft_printf("swap\n");
	return (second);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_b)
		return ;
	if (!*stack_a)
	{
		*stack_a = malloc(sizeof(t_stack) * 1);
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
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_a)
		return ;
	if (!*stack_b)
	{
		*stack_b = malloc(sizeof(t_stack) * 1);
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
	ft_printf("pb\n");
}

void	rotate(t_stack **stack, char c)
{
	int		temp;

	print_move(c, 'r');
	if (!*stack)
		return ;
	temp = (*stack)->content;
	while((*stack)->next)
	{
		(*stack) = (*stack)->next;
		(*stack)->prev->content = (*stack)->content;
	}
	(*stack)->content = temp;
	*stack = goto_head(*stack);
}

void	reverse_rotate(t_stack **stack, char c)
{
	int old_last;

	print_move(c, 'v');
	if (!*stack)
		return;
	while	((*stack)->next)
		*stack = (*stack)->next;
	old_last = (*stack)->content;
	while((*stack)->prev)
	{
		(*stack)->content = (*stack)->prev->content;
		*stack = (*stack)->prev;
	}
	(*stack)->content = old_last;
}

