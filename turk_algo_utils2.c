/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:23:16 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/24 13:06:04 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		cost_compare(t_stack *stack, int target)
{
	t_stack *temp_rot;
	t_stack *temp_rev_rot;
	int count;
	int count_rev;

	temp_rot = copy_stack_content(stack);
	temp_rev_rot = copy_stack_content(stack);
	if (!temp_rot || !temp_rev_rot)
		return(0);
	count = count_rot(temp_rot, target);
	count_rev = count_rev_rot(temp_rev_rot, target);
	free_stack_copy(goto_head(temp_rot));
	free_stack_copy(goto_head(temp_rev_rot));
	//ft_printf("rot : %d\n", count);
	//ft_printf("rev_rot : %d\n", count_rev);
	return (count - count_rev);
}

t_stack		*shadow_goto_biggest(t_stack *stack)
{
	int	biggest_temp;
	int i;
	stack = goto_head(stack);
	biggest_temp = stack->content;
	i = 0;
	while (len_stack(stack) >= (i + 1))
	{
		if (stack->content > biggest_temp)
			biggest_temp = stack->content;
		else
		stack = shadow_rotate(stack);
		i++;
	}
	ft_printf("biggest temp : %d\n", biggest_temp);
	ft_printf("stack content : %d\n", stack->content);
	return (stack);
}

int		show_smallest(t_stack *stack)
{
	int	smallest;
	int i;
	stack = goto_head(stack);
	smallest = stack->content;
	i = 0;
	while (len_stack(stack) >= (i + 1))
	{
		if (stack->content < smallest)
			smallest = stack->content;
		stack = shadow_rotate(stack);
		i++;
	}
	return (smallest);
}