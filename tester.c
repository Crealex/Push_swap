/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:23:07 by alexandre         #+#    #+#             */
/*   Updated: 2024/11/19 13:54:26 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_one_stack(t_stack *stack)
{
	int len;
	t_stack *temp;

	temp = copy_stack_content(stack);
	if (temp)
	{
		while (temp->prev)
		{
			temp = temp->prev;
		}
	}
	len = len_stack(temp);
	ft_printf(CYAN"\n----------------\n");
	ft_printf(BOLD"PILE :\n"END CYAN);
	if (temp)
	{
		while (temp->next)
		{
			ft_printf("  %d\n", temp->content);
			temp = temp->next;
		}
		ft_printf("  %d\n", temp->content);
	}
	ft_printf("la stack contient %d chiffre(s)\n", len);
	free_stack_copy(goto_head(temp));
}

void	read_stack(t_stack *stack_a, t_stack *stack_b)
{
	int len_a;
	int len_b;
	t_stack *temp_a;
	t_stack *temp_b;

	temp_a = copy_stack_content(stack_a);
	len_b = 0;
	if (temp_a)
	{
		while (temp_a->prev)
		{
			temp_a =temp_a->prev;
		}
	}
	len_a = len_stack(temp_a);
	ft_printf(CYAN"\n----------------\n");
	ft_printf(BOLD"PILE A:\n"END CYAN);
	if (temp_a)
	{
		while (temp_a->next)
		{
			ft_printf("  %d\n",temp_a->content);
		temp_a =temp_a->next;
		}
		ft_printf("  %d\n", temp_a->content);
	}
	ft_printf("la stack_a contient %d chiffre(s)\n", len_a);
	free_stack_copy(goto_head(temp_a));
	// -------------PILE B------------------
	if (stack_b)
	{
		temp_b = copy_stack_content(stack_b);
		while (temp_b->prev)
		{
			temp_b =temp_b->prev;
		}
		len_b = len_stack(temp_b);
	}
	ft_printf(BOLD"PILE B:\n"END CYAN);
	if (stack_b)
	{
		while (temp_b->next)
		{
			ft_printf("  %d\n", temp_b->content);
			temp_b = temp_b->next;
		}
		ft_printf("  %d\n", temp_b->content);
		free_stack_copy(goto_head(temp_b));
	}
	ft_printf("la stack_b contient %d chiffre(s)\n", len_b);
	ft_printf("----------------\n\n"END);
}

void	move_teser(t_stack *stack_a, t_stack *stack_b)
{
	read_stack(stack_a, stack_b);
	ft_printf(YELLOW BOLD"FONCTION SWAP:\n"END);
	ft_printf("test du mouvement swap, 1er num : %d\n", stack_a->content);
	ft_printf("test du mouvement swap 2eme num : %d\n", stack_a->next->content);
	ft_printf("----------SWAAAAAAAP----------\n");
	swap(&stack_a, 'a');
	ft_printf("test du mouvement swap, 1er num : %d\n", stack_a->content);
	ft_printf("test du mouvement swap 2eme num : %d\n", stack_a->next->content);
	read_stack(stack_a, stack_b);
	ft_printf(YELLOW BOLD"FONCTION PUSH_B\n"END);
	//ft_printf("1er satck a : %d\n", stack_a->content);
	//ft_printf("1er satck b : %d\n", stack_b->content);
	push_b(&stack_a, &stack_b);
	ft_printf("1er satck a : %d\n", stack_a->content);
	ft_printf("1er satck b : %d\n", stack_b->content);
	read_stack(stack_a, stack_b);
	/* ft_printf("test de push un max : ");
	while(stack_a)
	{
		push_b(&stack_a, &stack_b);
		read_stack(stack_a, stack_b);
	}
	// */push_b(&stack_a, &stack_b);
	read_stack(stack_a, stack_b);
	ft_printf(YELLOW BOLD"FONCTION PUSH_A\n"END);
	push_a(&stack_a, &stack_b);
	read_stack(stack_a, stack_b);
	ft_printf(YELLOW BOLD"FONCTION ROTATE (sur stack_a)\n"END);
	rotate(&stack_a, 'a');
	read_stack(stack_a, stack_b);
	ft_printf(YELLOW BOLD"FONCTION REVERSE ROTATE (sur stack_a)\n"END);
	reverse_rotate(&stack_a, 'a');
	read_stack(stack_a, stack_b);
}
