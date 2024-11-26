/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:24:38 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/26 16:45:36 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define BOLD "\033[1m"
# define END "\033[0m"
# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // Pour faire des tests
# include "libft/libft.h"
typedef struct s_stack
{
	int			content;
	int			index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;
typedef struct s_cost
{
	int		cost_a;     // Coût pour positionner dans la stack A
	int		cost_b;     // Coût pour positionner dans la stack B
	int		move_a;		// Choix du move de la stack a
	int		move_b;		// Choix du move de la stack b
	int		total_cost; // Coût total
	int		number;     // Le nombre concerné
	int		target;		// Le nombre cible
}	t_cost;
typedef struct s_target
{
	int		target_a;     // cible a atteidre dans la stack A
	int		target_b;     // cible a atteindre dans la stack B
	int		move_a;		  // choix du move stack a
	int		move_b;		  // choix du move stack b
}	t_target;
// parsing and checker
t_stack	*parsing(int argc, char **argv);
int		checker(int argc, char **argv);
// Move (push_swap_move_chained.c)
void	swap(t_stack **stack, char c);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack, char c);
void	reverse_rotate(t_stack **stack, char c);
// double move
void	double_rotate(t_stack **stack_a, t_stack **stack_b);
void	double_reverse_rotate(t_stack **stack_a, t_stack **stack_b);
// libft_pimp.c
t_stack	*ft_lstnew_pimp(int content);
void	ft_lstadd_back_pimp(t_stack **lst, t_stack *new);
// tester.c
void	move_teser(t_stack *stack_a, t_stack *stack_b); // test des moves et du parsing
void	read_stack(t_stack *stack_a, t_stack *stack_b); // Impresssion des stack
void	read_one_stack(t_stack *stack);
void	biggest_tester(t_stack *stack);
// push_swap_utils.c
int		len_stack(t_stack *stack); // calcule de la longeur de la liste
t_stack	*goto_head(t_stack *stack); //retour au premier element de la liste
int		is_sorted(t_stack *stack);
void	goto_biggest(t_stack **stack, char c);
void	print_move(char s, char m);
// push_swap_utils_2.c
void	update_index(t_stack *stack);
void	update_two_index(t_stack *stack_a, t_stack *stack_b);
t_stack	*copy_stack_content(t_stack *stack);
void	free_stack_copy(t_stack *stack);
int		is_smallest(t_stack *stack, int content);
// turk_algo_utils.c
int		show_biggest(t_stack *stack);
t_stack	*shadow_rotate(t_stack *stack);
t_stack	*shadow_reverse_rotate(t_stack *stack);
int		count_rot(t_stack *stack, int target);
int		count_rev_rot(t_stack *stack,int  target);
// turk_algo_utils2.c
int		cost_compare(t_stack *stack, int target);
t_stack		*shadow_goto_biggest(t_stack *stack);
int		show_smallest(t_stack *stack);
// turk algo
t_target	*find_choice(t_stack *stack_a, t_stack *stack_b);
void	exec_choice(t_stack **stack_a, t_stack **stack_b, t_target *choice);
void	turk_sort(t_stack **stack_a, t_stack **stack_b);
// algos
void	first_phase(t_stack *stack_a, t_stack *stack_b);
void	dirty_algo(t_stack **stack_a, t_stack **stack_b);
void	bignum_algo(t_stack **stack_a, t_stack **stack_b);
void	little_sort(t_stack **stack, char c);
// repush_in_a
void	repush_in_a(t_stack **stack_a, t_stack **stack_b);
// opti
int cost_choice(t_stack *stack, int target);
int	find_target_v2(int current, t_stack *stack);

#endif