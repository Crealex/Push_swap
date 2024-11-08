/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:59:43 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/08 11:23:02 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int i;
	t_stack *stack_a;
	//t_stack *stack_b;

	i = 1;
	stack_a = malloc(sizeof(t_stack) * argc);
	while(i < (argc - 1))
	{
		stack_a->content = ft_atoi(argv[i]);
		stack_a = stack_a->next;
		i++;
	}
	ft_printf("test du mouvement swap, 1er num : %d\n", stack_a->content);
	ft_printf("test du mouvement swap 2eme num : %d\n", stack_a->next->content);
	swap(stack_a);
	ft_printf("test du mouvement swap, 1er num : %d\n", stack_a->content);
	ft_printf("test du mouvement swap 2eme num : %d\n", stack_a->next->content);

}