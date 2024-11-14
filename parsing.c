/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:16:58 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/14 15:24:10 by atomasi          ###   ########.fr       */
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
		content = ft_atoi(res[i]);
		temp_a = ft_lstnew_pimp(content);
		ft_lstadd_back_pimp(stack, temp_a);
		i++;
	}
}

t_stack	*parsing(int argc, char **argv)
{
	int i;
	char **res;
	t_stack *stack_a;

	if (argc < 2)
	{
		ft_printf("\033[0;31mErreur, pas assez d'arguments\n");
		return (NULL);
	}
	if (!checker(argc, argv))
	{
		ft_printf(RED"ERREUR, ARGUMENTS INVALIDE\n");
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
