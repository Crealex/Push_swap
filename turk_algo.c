/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:31:29 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/19 18:07:09 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_target(int current, t_stack *stack)
{
	t_stack *temp;
	t_stack *target;

	if (!stack)
		return (NULL);
	temp = stack;
	target = stack;
	while (temp->next)
	{
		if (temp->content > current && temp->next->content < current)
			return (temp->next->content);
		temp = temp->next;
	}
	if (stack->content > current)
	{
		target = show_biggest(&stack);
		return (target->content);
	}
	else
	{
		target = show_biggest(&stack);
		return (target->next->content);
	}
}

int		cost_compare(t_stack *stack, int target)
{
	t_stack *temp;
	int count;
	int count_rev;

	temp = stack;
	count = 0;
	count_rev = 0;
	while (temp)
	{
		if (temp->content == target)
			break ;
		count++;
		shadow_rotate(&temp);
	}
	temp = stack;
	while (temp)
	{
		if (temp->content == target)
			break ;
		count_rev++;
		shadow_reverse_rotate(&temp);
	}
	return (count - count_rev);
}

int		cost_calculator(t_stack *stack, int target)
{
	// faire une fonction qui compte pour rotate et une qui compte pour reverse rotate (a faire dans turk_utils)
	t_stack *temp;
	int count;
	int choice;

	choice = cost_compare(stack, target);
	if (choice > 0)
	{
		while (temp)
		{
			if (temp->content == target)
				break ;
			count++;
			shadow_reverse_rotate(&temp);
		}
		return (count);
	}
	else
	{
		while (temp)
		{
			if (temp->content == target)
				break ;
			count++;
			shadow_rotate(&temp);
		}
		return (count);
	}
}

t_cost	*cost_parsing(t_stack *stack_a, t_stack *stack_b, int current_num)
{
	int		target;
	t_cost *res;

	res = malloc(sizeof(t_cost) * 1);
	res->number = current_num;
	//1. Trouver la position cible de chaque element.
	target = find_target(current_num, stack_b);
	//2. Calculer le couts des rotations stack_a.
	res->cost_a = cost_calculator(stack_a, current_num);
	//3. Calculer le couts des rotations stack_b.
	res->cost_b = cost_calculator(stack_b, target);
	res->total_cost = res->cost_a + res->cost_b;
	return (res);
}

void	turk_algo(t_stack **stack_a, t_stack **stack_b)
{
	t_cost	*smallest_cost;
	t_cost	*current_cost;
	t_stack	*temp_a;

	if (is_sorted(*stack_a))
		return ;
	if (len_stack(*stack_a) <= 3)
	{
		little_sort(*stack_a, 'a');
		return ;
	}
	temp_a = *stack_a;
	smallest_cost = cost_parsing(*stack_a, *stack_b, temp_a->content);
	while (temp_a)
	{
		current_cost = cost_parsing(*stack_a, *stack_b, temp_a->content);
		if (current_cost->total_cost < smallest_cost->total_cost)
			smallest_cost = current_cost;
		temp_a = temp_a->next;
	}
}
