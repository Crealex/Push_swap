/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:24:38 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/05 21:23:42 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // Pour faire des tests


#endif