/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:31:00 by mmisumi           #+#    #+#             */
/*   Updated: 2025/02/01 19:32:27 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (j);
}

char	**free_array(char **arr, int x)
{
	int	i;

	i = 0;
	while (i <= x)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**litsplit(char **arr, char const *s, char c)
{
	int	i;
	int	x;
	int	start;

	i = 0;
	x = 0;
	start = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		arr[x] = ft_substr(s, start, i - start);
		if (arr[x] == NULL)
			return (free_array(arr, x));
		x++;
	}
	arr[x] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	return (litsplit(arr, s, c));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && n > 1)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
