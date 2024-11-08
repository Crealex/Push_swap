/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:03:13 by atomasi           #+#    #+#             */
/*   Updated: 2024/10/09 14:25:34 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i1;
	int		i2;
	char	*result;

	i1 = 0;
	i2 = 0;
	result = malloc((len(s1) + len(s2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1[i1])
	{
		result[i1] = s1[i1];
		i1++;
	}
	while (s2[i2])
	{
		result[i1] = s2[i2];
		i1++;
		i2++;
	}
	result[i1] = '\0';
	return (result);
}
