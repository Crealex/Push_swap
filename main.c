/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:59:43 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/08 18:48:59 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int i;
	int content;
	t_stack *stack_a;
	t_stack *stack_a_temp;
	t_stack *stack_b;

		if (argc < 2)
	{
		ft_printf("\033[0;31mErreur, pas assez d'arguments\n");
		return (1);
	}
	i = 1;
	content = ft_atoi(argv[i++]);
	stack_a = ft_lstnew_pimp(content);
	stack_b = malloc(sizeof(t_stack) * argc);
	while(i < argc)
	{
		content = ft_atoi(argv[i]);
		stack_a_temp = ft_lstnew_pimp(content);
		ft_lstadd_back_pimp(&stack_a, stack_a_temp);
		i++;
	}
	ft_printf("FONCTION SWAP:\n");
	ft_printf("test du mouvement swap, 1er num : %d\n", stack_a->content);
	ft_printf("test du mouvement swap 2eme num : %d\n", stack_a->next->content);
	ft_printf("----------SWAAAAAAAP----------\n");
	stack_a = swap(stack_a);
	ft_printf("test du mouvement swap, 1er num : %d\n", stack_a->content);
	ft_printf("test du mouvement swap 2eme num : %d\n", stack_a->next->content);
	ft_printf("FONCTION PUSH_A\n");
	ft_printf("1er satck a : %d\n", stack_a->content);
	ft_printf("1er satck b : %d\n", stack_b->content);
	push_a(&stack_a, &stack_b);
	ft_printf("1er satck a : %d\n", stack_a->content);
	ft_printf("1er satck b : %d\n", stack_b->content);

}