/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:25:47 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/18 22:12:28 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// !!!A METTRE AU PROPRE!!!

#include "push_swap.h"

void	insert_in_b(t_stack **stack_a, t_stack **stack_b);

void	first_phase(t_stack *stack_a, t_stack *stack_b) // nom de la fonction provisoire
{
	t_stack *temp_a;
	t_stack	*temp_b;
	//premiere etape :
	ft_printf(YELLOW "AVANT TOUTE MANIP\n");
	read_stack(stack_a, stack_b);
	temp_a = stack_a;
	temp_b = stack_b;
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);

	// insertion d'un nombre au bonne endroit de la satck_b
	while (temp_a)
	{
		insert_in_b(&stack_a, &stack_b);
		read_stack(stack_a, stack_b);
		temp_a = temp_a->next;
	}
	// renvoi: dans la stack_a
	while (temp_b)
	{
		ft_printf("push_a\n");
		push_a(&stack_a, &stack_b);
		temp_b = temp_b->next;
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
	rotate(stack_b, 'b');
}

void	insert_middle(t_stack **stack_a, t_stack **stack_b)
{
	// IMPOSSIBLE DE DEPLACER CE PUTAIN DE TEMP_A
	*stack_a = goto_head(*stack_a);
	while ((*stack_a)->next)
	{
		if ((*stack_a)->content < (*stack_b)->content && (*stack_a)->content > (*stack_b)->next->content)
		{
			rotate(stack_b, 'b');
			push_b(stack_a, stack_b);
			break ;
		}
		else
		{
			rotate(stack_b, 'b');
		}
		(*stack_a) = (*stack_a)->next;
		read_stack(*stack_a, *stack_b);
	}
	*stack_a = goto_head(*stack_a);
}

void	insert_in_b(t_stack **stack_a, t_stack **stack_b)
{
	static int max_num;
	static int min_num;
	printf("Content de a : %d\n", (*stack_a)->content);
	if ((*stack_a)->next && !max_num && !min_num)
	{
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
	}
	else if (!max_num && !min_num)
	{
		max_num = (*stack_a)->content;
		min_num = INT_MIN;
	}
	ft_printf("TESSSSSST : %d\n", max_num);
	if ((*stack_a)->content > max_num)
	{
		ft_printf("MAXXXX\n");
		max_num = (*stack_a)->content;
		insert_max(stack_a, stack_b);
	}
	else if ((*stack_a)->content < min_num)
	{
		ft_printf("MINNNNN\n");
		min_num = (*stack_a)->content;
		insert_min(stack_a, stack_b);
	}
	else
		insert_middle(stack_a, stack_b);
	ft_printf("MIDDDDDDD:E and max num : %d\n", max_num);
}
