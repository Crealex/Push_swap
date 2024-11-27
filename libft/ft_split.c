/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:34:06 by atomasi           #+#    #+#             */
/*   Updated: 2024/11/27 15:28:44 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **res, int i)
{
	while (i >= 0)
	{
		if (res[i])
			free(res[i]);
		i--;
	}
	free(res);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static int	alloc_words(char **res, const char *s, char c)
{
	int	word;
	int	len;
	int	i;

	word = 0;
	i = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			res[word] = malloc(sizeof(char) * (len + 1));
			if (!res[word++])
				return (0);
		}
	}
	res[word] = NULL;
	return (1);
}

static void	fill_words(char **res, const char *s, char c)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			res[w][j] = '\0';
			w++;
			j = 0;
			while (s[i] == c)
				i++;
			continue ;
		}
		res[w][j++] = s[i++];
	}
	if (w < count_words(s, c))
		res[w][j] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	res = malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);
	if (!alloc_words(res, s, c))
	{
		ft_free_split(res, word_count);
		return (NULL);
	}
	if (word_count > 0)
		fill_words(res, s, c);
	return (res);
}
