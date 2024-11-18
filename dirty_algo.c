/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirty_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:53:10 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/18 17:15:52 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_in_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;

	//printf(RED"test\n"END);
	temp_b = *stack_b;
	goto_head(temp_b);
	while (temp_b->next)
	{
		if (((*stack_a)->content > temp_b->content && (*stack_a)->content < temp_b->next->content)
		 || ((*stack_a)->content < temp_b->content && (*stack_a)->content > temp_b->next->content))
		{
			*stack_b = temp_b;
			rotate(stack_b);
			push_b(stack_a, stack_b);
			ft_printf(YELLOW"insertion entre 2 valeurs :\n"END);
			read_stack(*stack_a, *stack_b); // pour verif un truc
			return ;
		}
		//ft_printf(YELLOW"%d\n"END, (*stack_a)->content); // pour verif un truc
		ft_printf(RED"temp->content : %d\n", temp_b->content);
		ft_printf(RED"temp->next->content : %d\n", temp_b->next->content);
		ft_printf(RED"stack_a->content : %d\n", (*stack_a)->content);
		temp_b = temp_b->next;
	}
	if ((*stack_a)->content > (*stack_b)->content)
	{
		ft_printf(YELLOW"insertion du plus gros :\n"END);
		goto_biggest(stack_b);
		push_b(stack_a, stack_b);
		read_stack(*stack_a, *stack_b); // pour verif un truc
	}
	else
	{
		ft_printf(YELLOW"insertion du plus petit :\n"END);
		goto_biggest(stack_b);
		push_b(stack_a, stack_b);
		rotate(stack_b);
		read_stack(*stack_a, *stack_b); // pour verif un truc
	}
}

void	dirty_algo(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (is_sorted(*stack_a))
		return ;
	while (!is_sorted(*stack_a))
	{
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		temp_a = *stack_a;
		ft_printf(YELLOW"avant de rentrer dans la boucle : \n"END);
		read_stack(*stack_a, *stack_b);
		while (temp_a)
		{
			insert_in_b(stack_a, stack_b);
			temp_a = *stack_a; // pas sur du truc
			temp_a = temp_a->next;
		}
		insert_in_b(stack_a, stack_b);
		// renvoi dans la stack_a
		read_stack(*stack_a, *stack_b);
		temp_b = *stack_b;
		while (temp_b)
		{
			push_a(stack_a, stack_b);
			if (*stack_b)
				temp_b = *stack_b;
			temp_b = temp_b->next;
		}
		push_a(stack_a, stack_b);
	}
	//push_a(stack_a, stack_b);
	return ;
}
