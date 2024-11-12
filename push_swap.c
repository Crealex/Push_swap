/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:25:47 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/12 15:37:32 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// !!!A METTRE AU PROPRE!!!

#include "push_swap.h"

void	insert_in_b(t_stack **stack_a, t_stack **stack_b);

void	first_phase(t_stack *stack_a, t_stack *stack_b) // nom de la fonction provisoire
{
	//premiere etape :
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);

	// insertion d'un nombre au bonne endroit de la satck_b
	ft_printf("avant l'algo :\n");
	read_stack(stack_a, stack_b);
	// appel de insert_middle
	insert_in_b(&stack_a, &stack_b);
	ft_printf("pendant l'algo :\n");
	read_stack(stack_a, stack_b);
	// renvoie dans la stack_a
	while (stack_b)
	{
		push_a(&stack_a, &stack_b);
		ft_printf("push_a\n");
		stack_b = stack_b->next;
	}
	stack_b = goto_head(stack_b);
	printf("apres l'algo :\n");
	read_stack(stack_a, stack_b);
	return ;
}


void	insert_max(t_stack	**stack_a, t_stack **stack_b)
{
	int temp_max;
	while ((*stack_b)->prev)
		*stack_b = (*stack_b)->prev;
	while (*stack_b)
	{
		if ((*stack_b)->content >= temp_max)
		{
			if (temp_max == (*stack_b)->content)
				break;
			temp_max = (*stack_b)->content;
		}
		*stack_b = (*stack_b)->next;
	}
	push_b(stack_a, stack_b);
	return ;
}

void	insert_min(t_stack **stack_a, t_stack **stack_b)
{
	insert_max(stack_a, stack_b);
	*stack_b = rotate(*stack_b);
}

void	insert_middle(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a)
	{
		if ((*stack_a)->content < (*stack_b)->content && (*stack_a)->content > (*stack_b)->next->content)
		{
			*stack_b = rotate(*stack_b);
			ft_printf("rotate\n");
			push_b(stack_a, stack_b);
			ft_printf("push_b\n");
		}
		else
			*stack_b = rotate(*stack_b);
		*stack_a = (*stack_a)->next;
		ft_printf("rotate\n");
	}
}

void	insert_in_b(t_stack **stack_a, t_stack **stack_b)
{
	int max_num;
	int min_num;

	ft_printf("test\n");
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		max_num = (*stack_a)->content;
		min_num = (*stack_a)->next->content;
	}
	else
	{
		max_num = (*stack_a)->next->content;
		min_num = (*stack_a)->content;
	}
	if ((*stack_a)->content > max_num)
	{
		max_num = (*stack_a)->content;
		insert_max(stack_a, stack_b);
	}
	else if ((*stack_a)->content < min_num)
	{
		min_num = (*stack_a)->content;
		insert_min(stack_a, stack_b);
	}
	else
		insert_middle(stack_a, stack_b);
}
