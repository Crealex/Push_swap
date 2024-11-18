/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:58:17 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/18 22:09:16 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		len_stack(t_stack *stack)
{
	int i;

	i = 0;
	if (stack)
	{
		while (stack->prev)
		{
			stack = stack->prev;
		}
		while (stack->next)
		{
			i++;
			stack = stack->next;
		}
		i++;
	}
	return (i);
}

t_stack	*goto_head(t_stack *stack)
{
	while (stack->prev)
	{
		stack = stack->prev;
	}
	return (stack);
}
void	goto_biggest(t_stack **stack, char c)
{
	int		biggest_temp;
	t_stack	*temp;

	biggest_temp = (*stack)->content;
	temp = *stack;
	while (temp)
	{
		if (temp->content > biggest_temp)
			biggest_temp = temp->content;
		temp = temp->next;
	}
	while ((*stack)->content != biggest_temp)
		rotate(stack, c); // a modif
}

int		is_sorted(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void	print_move(char s, char m)
{
	if (m == 'r')
	{
		if (s == 'a')
			ft_printf("ra\n");
		else if (s == 'b')
			ft_printf("rb\n");
	}
	else if (m == 's')
	{
		if (s == 'a')
			ft_printf("sa\n");
		else if (s == 'b')
			ft_printf("sb\n");
	}
	else if (m == 'v')
	{
		if (s == 'a')
			ft_printf("rra\n");
		else if (s == 'b')
			ft_printf("rrb\n");
	}
}
