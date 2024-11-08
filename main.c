/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:59:43 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/08 13:43:52 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int i;
	int content;
	t_list *stack_a;
	t_list *stack_a_temp;

	//t_list *stack_b;

	i = 1;
	content = ft_atoi(argv[i++]);
	stack_a = ft_lstnew(&content);
	while(i < argc)
	{
		content = ft_atoi(argv[i]);
		stack_a_temp = ft_lstnew(&content);
		ft_lstadd_back(&stack_a, stack_a_temp);
		i++;
	}
	ft_printf("test du mouvement swap, 1er num : %d\n", stack_a->content);
	ft_printf("test du mouvement swap 2eme num : %d\n", stack_a->next->content);
	swap(stack_a);
	ft_printf("test du mouvement swap, 1er num : %d\n", stack_a->content);
	ft_printf("test du mouvement swap 2eme num : %d\n", stack_a->next->content);

}