/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:58:17 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/27 14:10:26 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	len_stack(t_stack *stack)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = copy_stack_content(stack);
	if (temp)
	{
		while (temp->prev)
		{
			temp = temp->prev;
		}
		while (temp->next)
		{
			i++;
			temp = temp->next;
		}
		i++;
	}
	free_stack_copy(goto_head(temp));
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
	temp = copy_stack_content(*stack);
	while (temp->next)
	{
		if (temp->content > biggest_temp)
			biggest_temp = temp->content;
		temp = temp->next;
	}
	if (temp->content > biggest_temp)
		biggest_temp = temp->content;
	free_stack_copy(goto_head(temp));
	while ((*stack)->content != biggest_temp)
		rotate(stack, c);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

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
