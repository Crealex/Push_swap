/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_chained.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:07:05 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/21 11:23:03 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char c)
{
	int temp;

	print_move(c, 's');
	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	//update_index(*stack);
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
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(temp);
		(*stack_b)->prev = NULL;
		ft_printf("pa\n");
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
		*stack_b = ft_calloc(sizeof(t_stack), 1);
		(*stack_b)->content = (*stack_a)->content;
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
		(*stack_a)->prev = NULL;
		ft_printf("pb\n");
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
	//update_index(*stack);
}

void	reverse_rotate(t_stack **stack, char c)
{
	int old_last;

	print_move(c, 'v');
	if (!*stack)
		return;
	while ((*stack)->next)
		*stack = (*stack)->next;
	old_last = (*stack)->content;
	while((*stack)->prev)
	{
		(*stack)->content = (*stack)->prev->content;
		*stack = (*stack)->prev;
	}
	(*stack)->content = old_last;
	//update_index(*stack);
}

