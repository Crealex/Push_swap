/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:24:38 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/14 16:40:00 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BOLD "\033[1m"
# define END "\033[0m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define RED "\033[0;31m"
# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // Pour faire des tests
#include "libft/libft.h"
typedef struct s_stack
{
	int			content;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;
t_stack	*parsing(int argc, char **argv);
int		checker(int argc, char **argv);
t_stack	*swap(t_stack *stack);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
t_stack	*reverse_rotate(t_stack *stack);
t_stack	*ft_lstnew_pimp(int content);
void	ft_lstadd_back_pimp(t_stack **lst, t_stack *new);
void	move_teser(t_stack *stack_a, t_stack *stack_b); // test des moves et du parsing
void	read_stack(t_stack *stack_a, t_stack *stack_b); // Impresssion des stack
int		len_stack(t_stack *stack); // calcule de la longeur de la liste
t_stack	*goto_head(t_stack *stack); //retour au premier element de la liste
void	first_phase(t_stack *stack_a, t_stack *stack_b);

#endif