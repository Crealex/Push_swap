/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:06:24 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/14 15:35:07 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checker(int argc, char **argv)
{
	int i;
	int j;
	char **res;

	i = 1;
	while (i < argc)
	{
			res = ft_split(argv[i], ' ');
			i++;
	}
	i = 0;
	while(res[i])
	{
		while(res[i][j])
		{
			if (res[i][j] < 47 || res[i][j] > 58)
				return (0);
			else if ()
		}
	}
}
