/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:16:58 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/15 15:10:11 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		duplicate_checker(t_stack *stack, int content)
{
	while (stack)
	{
		if (stack->content == content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		put_in_stack(t_stack **stack, char **res)
{
	int i;
	int content;
	t_stack *temp_a;

	i = 0;
	while (res[i])
	{
		content = ft_atoi(res[i]);
		if (!duplicate_checker(*stack, content))
			return (0);
		temp_a = ft_lstnew_pimp(content);
		ft_lstadd_back_pimp(stack, temp_a);
		i++;
	}
	return (1);
}

t_stack	*parsing(int argc, char **argv)
{
	int i;
	char **res;
	t_stack *stack_a;

	stack_a = NULL;
	//Check nombre valide
	if (!checker(argc, argv))
	{
		return (NULL);
	}
	i = 1;
	// parsing
	while (i < argc)
	{
		res = ft_split(argv[i], ' ');
		if (!put_in_stack(&stack_a, res))
			return (NULL);
		free(res);
		i++;
	}
	return (stack_a);
}