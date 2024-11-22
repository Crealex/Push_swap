/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:13:38 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/22 21:06:30 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	update_index(t_stack *stack)
{
	int i;
	t_stack *current;

	current = stack;
	i = 0;
	while (current)
	{
		current->index = i;
		i++;
		current = current->next;
	}
} */

void	update_two_index(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return;
	//update_index(stack_a);
	//update_index(stack_b);
}

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
		new->next = malloc(sizeof(t_stack));
		if (!new->next)
		{
			free_stack_copy(head);
			return (NULL);
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
