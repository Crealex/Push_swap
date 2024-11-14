/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:16:58 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/14 17:20:11 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_in_stack(t_stack **stack, char **res)
{
	int i;
	int content;
	t_stack *temp_a;

	i = 0;
	while (res[i])
	{
		content = ft_atoi(res[i]);
		temp_a = ft_lstnew_pimp(content);
		ft_printf(YELLOW"TEST\n"END);
		ft_lstadd_back_pimp(stack, temp_a);
		i++;
	}
}

t_stack	*parsing(int argc, char **argv)
{
	int i;
	char **res;
	t_stack *stack_a;

	stack_a = NULL;
	if (!checker(argc, argv))
	{
		return (NULL);
	}
	i = 1;
	// parsing
	while (i < argc)
	{
		res = ft_split(argv[i], ' ');
		put_in_stack(&stack_a, res);
		i++;
	}
	return (stack_a);
}
