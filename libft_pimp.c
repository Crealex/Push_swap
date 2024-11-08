/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_pimp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:50:57 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/08 15:48:27 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack	*ft_lstnew_pimp(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_pimp(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (*lst == NULL)
	{
		ft_printf("test\n");
		*lst = new;
		return ;
	}
	if (new == NULL)
		return ;
	temp = *lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}