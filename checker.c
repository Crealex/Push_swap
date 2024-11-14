/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:06:24 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/14 17:25:28 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Checker echoue quand ce n'est pas le dernier qui est invalide et c'est bizarre
int		int_max_min(char *str)
{
	if (str[0] == '-')
	{
		//int min
		if (ft_strlen(str) == 11)
		{
			if (ft_strncmp(str, "-2147483648", INT_MAX) > 0)
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
			if (ft_strncmp(str, "2147483647", INT_MAX) > 0)
				return (0);
		}
		else if (ft_strlen(str) > 10)
			return (0);
		return (1);
	}
}

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
		j = 0;
		while(res[i][j])
		{
			if ((res[i][j] < 47 || res[i][j] > 58) && res[i][0] != '-')
				return (0);
			j++;
		}
		if (!int_max_min(res[i]))
			return (0);
		i++;
	}
	ft_printf(YELLOW"testtt\n"END);
	return (1);
}
