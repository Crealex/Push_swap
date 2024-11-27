/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:13:38 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/27 14:11:15 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*copy_stack_content(t_stack *stack)
{
	t_stack	*new;
	t_stack	*temp;
	t_stack	*head;

	if (!stack)
		return (NULL);
	new = ft_lstnew_pimp(stack->content);
	if (!new)
		return (NULL);
	head = new;
	temp = stack->next;
	while (temp)
	{
		new->next = ft_calloc(sizeof(t_stack), 1);
		if (!new->next)
		{
			return (free_stack_copy(head), NULL);
		}
		new->next->content = temp->content;
		new->next->prev = new;
		new = new->next;
		temp = temp->next;
	}
	new->next = NULL;
	return (goto_head(head));
}

void	free_stack_copy(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

int	is_smallest(t_stack *stack, int content)
{
	while (stack->next)
	{
		if (stack->content < content)
		{
			return (0);
		}
		stack = stack->next;
	}
	if (stack->content < content)
	{
		return (0);
	}
	goto_head(stack);
	return (1);
}
