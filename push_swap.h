/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:24:38 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/08 11:15:31 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // Pour faire des tests
#include "libft/libft.h"
typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;
t_stack	*swap(t_stack *stack);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
t_stack	*rotate(t_stack *stack);
t_stack	*reverse_rotate(t_stack *stack);

#endif