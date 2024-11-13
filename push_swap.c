/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:25:47 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/13 21:58:56 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// !!!A METTRE AU PROPRE!!!

#include "push_swap.h"

void	insert_in_b(t_stack **stack_a, t_stack **stack_b);

void	first_phase(t_stack *stack_a, t_stack *stack_b) // nom de la fonction provisoire
{
	t_stack *temp_a;
	//premiere etape :
	ft_printf(YELLOW "AVANT TOUTE MANIP\n");
	read_stack(stack_a, stack_b);
	temp_a = stack_a;
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	read_stack(stack_a, stack_b);

	// insertion d'un nombre au bonne endroit de la satck_b
	while (temp_a)
	{
		ft_printf("avant l'algo :\n");
		read_stack(stack_a, stack_b);
		// appel de insert_middle
		insert_in_b(&stack_a, &stack_b);
		ft_printf("pendant l'algo :\n");
		read_stack(stack_a, stack_b);
		temp_a = temp_a->next;
	}
	// renvoi: dans la stack_a
	while (stack_b)
	{
		push_a(&stack_a, &stack_b);
		ft_printf("push_a\n");
		stack_b = stack_b->next;
	}
	stack_b = goto_head(stack_b);
	read_stack(stack_a, stack_b);
	return ;
}


void	insert_max(t_stack	**stack_a, t_stack **stack_b)
{
	int temp_max;

	temp_max = INT_MIN;
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
	read_stack(*stack_a, *stack_b);
	return ;
}

void	insert_min(t_stack **stack_a, t_stack **stack_b)
{
	insert_max(stack_a, stack_b);
	rotate(stack_b);
}

void	insert_middle(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp_a;

	temp_a = *stack_a;
	temp_a->next = (*stack_a)->next;
	// IMPOSSIBLE DE DEPLACER CE PUTAIN DE TEMP_A
	while (temp_a)
	{
		if (temp_a->content < (*stack_b)->content && temp_a->content > (*stack_b)->next->content)
		{
			rotate(stack_b);
			read_stack(*stack_a, *stack_b);
			push_b(stack_a, stack_b);
		}
		else
		{
			rotate(stack_b);
		}
		temp_a = temp_a->next;
		ft_printf("current a : %d\n", (*stack_a)->content);
		ft_printf("boucle dans middles\n");
		read_stack(*stack_a, *stack_b);
	}
}

void	insert_in_b(t_stack **stack_a, t_stack **stack_b)
{
	int max_num;
	int min_num;
	printf("Content de a : %d\n", (*stack_a)->content);
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
	ft_printf("TESSSSSST\n");
	if ((*stack_a)->content > max_num)
	{
		max_num = (*stack_a)->content;
		insert_max(stack_a, stack_b);
		ft_printf("MAXXXX\n");
	}
	else if ((*stack_a)->content < min_num)
	{
		min_num = (*stack_a)->content;
		insert_min(stack_a, stack_b);
		ft_printf("MINNNNN\n");
	}
	else
		insert_middle(stack_a, stack_b);
	ft_printf("MIDDDDDDD:E and max num : %d\n", max_num);
}
