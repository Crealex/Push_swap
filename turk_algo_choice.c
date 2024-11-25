/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_choice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:31:29 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/22 21:35:52 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_target(int current, t_stack *stack)
{
	t_stack *temp;

	int num;
	if (!stack)
		return (0);
	temp = copy_stack_content(stack);
	temp = shadow_goto_biggest(temp);
	temp = goto_head(temp);
	while (temp->next)
	{
		if ((temp->content > current && temp->next->content < current))
		{
			num = temp->next->content;
			free_stack_copy(goto_head(temp));
			ft_printf("current when into 2 numbers : %d\n", current);
			return (num);
		}
		temp = temp->next;
	}
	free_stack_copy(goto_head(temp));
	//tester quel current amene ici et peut etre quel content
	ft_printf("current when show biggest: %d\n", current);
	ft_printf("boggest : %d", show_biggest(stack));
	return (show_biggest(stack));
}

int		find_target2(int current, t_stack *stack)
{
	int biggest;
	int smallest;
	int num;
	t_stack *temp;

	biggest = show_biggest(stack);
	smallest = show_smallest(stack);
	if (current > biggest || current < smallest) // si min rotate plus loin
		return (biggest);
	temp = copy_stack_content(stack);
	temp = shadow_goto_biggest(temp); // ranger la pile par ordre decroissant
	while (temp->next)
	{
		if (temp->content < current)
		{
			num = temp->next->content;
			free_stack_copy(temp);
			return (num);
		}
		temp = temp->next;
	}
	return (0);
}

int		cost_calculator(t_stack *stack, int target)
{
	int choice;

	choice = 0;
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

void	copy_cost(t_cost *smallest_cost, t_cost *current_cost)
{
	smallest_cost->cost_a = current_cost->cost_a;
	smallest_cost->cost_b = current_cost->cost_b;
	smallest_cost->number = current_cost->number;
	smallest_cost->target = current_cost->target;
	smallest_cost->total_cost = current_cost->total_cost;
}

t_target	*find_choice(t_stack *stack_a, t_stack *stack_b)
{
	t_cost	*smallest_cost;
	t_cost	*current_cost;
	t_target *res;
	t_stack	*temp_a;

	temp_a = copy_stack_content(stack_a);
	current_cost = NULL;
	smallest_cost = NULL;
	smallest_cost = cost_parsing(stack_a, stack_b, temp_a->content);
	res = malloc(sizeof(t_target) * 1);
	temp_a = temp_a->next;
	while (temp_a->next)
	{
		current_cost = cost_parsing(stack_a, stack_b, temp_a->content);
		if (current_cost->total_cost < smallest_cost->total_cost)
			copy_cost(current_cost, smallest_cost);
		free(current_cost);
		temp_a = temp_a->next;
	}
	res->target_a = smallest_cost->number;
	res->target_b = smallest_cost->target ;
	ft_printf("choice : %d\n", smallest_cost->number);
	ft_printf("target : %d\n", smallest_cost->target);
	read_stack(stack_a, stack_b);
	free_stack_copy(goto_head(temp_a));
	free(smallest_cost);
	return (res);
}
