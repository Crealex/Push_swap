/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:25:47 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/27 14:46:13 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	stack_a = parsing(argc, argv);
	if (!stack_a)
	{
		ft_putendl_fd(RED"Error"END, 2);
		return (1);
	}
	if (len_stack(stack_a) == 2)
	{
		if ((stack_a)->content > (stack_a)->next->content)
			swap(&stack_a, 'a');
	}
	else if (len_stack(stack_a) == 3)
		little_sort(&stack_a, 'a');
	else
		turk_sort(&stack_a, &stack_b);
	if (stack_a)
		free_stack_copy(stack_a);
	return (0);
}
