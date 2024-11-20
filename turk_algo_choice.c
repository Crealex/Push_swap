/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_choice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:31:29 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/20 15:22:07 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_target(int current, t_stack *stack)
{
	t_stack *temp;
	t_stack *target;
	if (!stack)
		return (0);
	temp = stack;
	target = stack;
	while (temp->next)
	{
		if ((temp->content > current && temp->next->content < current))
		{
			return (temp->next->content);
		}
		temp = temp->next;
	}
	if (stack->content > current)
	{
		target = show_biggest(stack);
		return (target->content);
	}
	else
	{
		target = show_biggest(stack);
		return (target->next->content);
	}
}

int		cost_calculator(t_stack *stack, int target)
{
	int choice;

	choice = cost_compare(stack, target);
	if (choice > 0)
		return (count_rev_rot(stack, target));
	else
		return (count_rot(stack, target));
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
	//4. Cout total
	res->total_cost = res->cost_a + res->cost_b;
	res->target = target;
	return (res);
}

t_target	*find_choice(t_stack *stack_a, t_stack *stack_b)
{
	t_cost	*smallest_cost;
	t_cost	*current_cost;
	t_target *res;
	t_stack	*temp_a;

	temp_a = stack_a;
	smallest_cost = cost_parsing(stack_a, stack_b, temp_a->content);
	res = malloc(sizeof(t_target) * 1);
	temp_a = temp_a->next;
	while (temp_a->next)
	{
		current_cost = cost_parsing(stack_a, stack_b, temp_a->content);
		if (current_cost->total_cost < smallest_cost->total_cost)
			smallest_cost = current_cost;
		temp_a = temp_a->next;
	}
	res->target_a = smallest_cost->number;
	res->target_b = smallest_cost->target;
	return (res);
}
