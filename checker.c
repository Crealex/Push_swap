/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:06:24 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/15 15:10:03 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		int_max_min(char *str)
{
	if (str[0] == '-')
	{
		//int min
		if (ft_strlen(str) == 11)
		{
			if (ft_strncmp(str, "-2147483648", 11) > 0)
				return (0);
		}
		else if (ft_strlen(str) > 11)
			return (0);
		return (1);
	}
	else
	{
		//int max
		if (ft_strlen(str) == 10)
		{
			if (ft_strncmp(str, "2147483647", 10) > 0)
				return (0);
		}
		else if (ft_strlen(str) > 10)
			return (0);
		return (1);
	}
}

int	num_checker(char **res)
{
	int i;
	int j;

	i = 0;
	while (res[i])
	{
		j = 0;
		while(res[i][j])
		{
			if ((res[i][j] < '0' || res[i][j] > '9') && res[i][0] != '-')
			{
				ft_free_split(res, i);
				return (0);
			}
			j++;
		}
		if (!int_max_min(res[i]))
		{
			ft_free_split(res, i);
			return (0);
		}
		i++;
	}
	ft_free_split(res, i);
	return (1);
}


int		checker(int argc, char **argv)
{
	int 	i;
	char	**res;

	i = 1;
	while (i < argc)
	{
		res = ft_split(argv[i], ' ');
		if (!num_checker(res))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

