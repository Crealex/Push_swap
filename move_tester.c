/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:23:07 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/09 15:35:33 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *prev_a;
	t_stack *prev_b;

	ft_printf(CYAN"\n----------------\n");
	ft_printf(BOLD"PILE A:\n"END CYAN);
	while (stack_a->next)
	{
		ft_printf("  %d\n", stack_a->content);
		prev_a = stack_a;
		stack_a = stack_a->next;
		stack_a->prev = prev_a;
	}
	ft_printf("  %d\n", stack_a->content);
	//retour au debut
	while(stack_a->prev)
	{
		stack_a = stack_a->prev;
	}
	// -------------PILE B------------------
	ft_printf(BOLD"PILE B:\n"END CYAN);
	while (stack_b->next)
	{
		ft_printf("  %d\n", stack_b->content);
		prev_b = stack_b;
		stack_b = stack_b->next;
		stack_b->prev = prev_b;
	}
	ft_printf("  %d\n", stack_b->content);
	//retour au debut
	while(stack_b->prev)
	{
		stack_b = stack_b->prev;
	}
	ft_printf("----------------\n\n"END);
}

void	move_teser(t_stack *stack_a, t_stack *stack_b)
{
	read_stack(stack_a, stack_b);
	ft_printf(YELLOW BOLD"FONCTION SWAP:\n"END);
	ft_printf("test du mouvement swap, 1er num : %d\n", stack_a->content);
	ft_printf("test du mouvement swap 2eme num : %d\n", stack_a->next->content);
	ft_printf("----------SWAAAAAAAP----------\n");
	stack_a = swap(stack_a);
	ft_printf("test du mouvement swap, 1er num : %d\n", stack_a->content);
	ft_printf("test du mouvement swap 2eme num : %d\n", stack_a->next->content);
	read_stack(stack_a, stack_b);
	ft_printf(YELLOW BOLD"FONCTION PUSH_B\n"END);
	ft_printf("1er satck a : %d\n", stack_a->content);
	ft_printf("1er satck b : %d\n", stack_b->content);
	push_b(&stack_a, &stack_b);
	ft_printf("1er satck a : %d\n", stack_a->content);
	ft_printf("1er satck b : %d\n", stack_b->content);
	read_stack(stack_a, stack_b);
	ft_printf("(2x push_b de plus pour avoir des trucs dans les deux stack)");
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	read_stack(stack_a, stack_b);
	ft_printf(YELLOW BOLD"FONCTION PUSH_A\n"END);
	push_a(&stack_a, &stack_b);
	read_stack(stack_a, stack_b);
	ft_printf(YELLOW BOLD"FONCTION ROTATE (sur stack_a)\n"END);
	stack_a = rotate(stack_a);
	read_stack(stack_a, stack_b);
	ft_printf(YELLOW BOLD"FONCTION REVERSE ROTATE (sur stack_a)\n"END);
	stack_a = reverse_rotate(stack_a);
	read_stack(stack_a, stack_b);
}
