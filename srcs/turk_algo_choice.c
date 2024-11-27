/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_choice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:31:29 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/27 13:38:04 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int find_target(int current, t_stack *stack)
{
	t_stack *temp;
	t_stack *first;

	if (!stack)
		return (0);

	temp = stack;
	first = stack;
	while (temp->next)
	{
		if ((temp->content > current && temp->next->content < current))
			return (temp->next->content);
		temp = temp->next;
	}
	if (temp->content > current && first->content < current)
		return (first->content);
	return (show_biggest(stack));
}

int	cost_calculator(t_stack *stack, int target, t_cost *res, char c)
{
	int	choice;

	choice = 0;
	choice = cost_choice(stack, target);
	if (choice == -1)
	{
		if (c == 'a')
			res->move_a = choice;
		else if (c == 'b')
			res->move_b = choice;
		return (count_rev_rot(stack, target));
	}
	else
	{
		if (c == 'a')
			res->move_a = choice;
		else if (c == 'b')
			res->move_b = choice;
		return (choice);
	}
}

t_cost	*cost_parsing(t_stack *stack_a, t_stack *stack_b, int current_num)
{
	int		target;
	t_cost	*res;

	res = malloc(sizeof(t_cost) * 1);
	res->number = current_num;
	target = find_target(current_num, stack_b);
	res->cost_a = cost_calculator(stack_a, current_num, res, 'a');
	res->cost_b = cost_calculator(stack_b, target, res, 'b');
	res->total_cost = res->cost_a + res->cost_b;
	res->target = target;
	return (res);
}

void	copy_cost(t_cost *smallest_cost, t_cost *current_cost)
{
	smallest_cost->cost_a = current_cost->cost_a;
	smallest_cost->cost_b = current_cost->cost_b;
	smallest_cost->number = current_cost->number;
	smallest_cost->move_a = current_cost->move_a;
	smallest_cost->move_b = current_cost->move_b;
	smallest_cost->target = current_cost->target;
	smallest_cost->total_cost = current_cost->total_cost;
}

t_target	*find_choice(t_stack *stack_a, t_stack *stack_b)
{
	t_cost		*smallest_cost;
	t_cost		*current_cost;
	t_target	*res;
	t_stack		*temp_a;

	temp_a = copy_stack_content(stack_a);
	current_cost = NULL;
	smallest_cost = NULL;
	smallest_cost = cost_parsing(stack_a, stack_b, temp_a->content);
	res = malloc(sizeof(t_target) * 1);
	while (temp_a->next)
	{
		temp_a = temp_a->next;
		current_cost = cost_parsing(stack_a, stack_b, temp_a->content);
		if (current_cost->total_cost < smallest_cost->total_cost)
			copy_cost(smallest_cost, current_cost);
		free(current_cost);
	}
	res->target_a = smallest_cost->number;
	res->target_b = smallest_cost->target;
	res->move_a = smallest_cost->move_a;
	res->move_b = smallest_cost->move_b;
	free_stack_copy(goto_head(temp_a));
	free(smallest_cost);
	return (res);
}
