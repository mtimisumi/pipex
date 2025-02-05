/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:32:25 by mmisumi           #+#    #+#             */
/*   Updated: 2025/01/29 18:57:49 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t  i;
    size_t  len;
    len = ft_strlen(src);
    i = 0;
    if (size == 0)
        return (len);
    while (src[i] != '\0' && i < size - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (len);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	ptr = malloc(len * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;
	size_t	strlen;

	strlen = ft_strlen(s);
	i = start;
	j = 0;
	if (start >= strlen)
		return (ft_strdup(""));
	if (start + len > strlen)
		len = strlen - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (j < len)
	{
		substr[j] = s[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

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

char	*getpath(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (strncmp(envp[i], "PATH=", 5)== 0)
			return (envp[i] += 5);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*newstring;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	newstring = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (newstring == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		newstring[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		newstring[i] = *s2;
		i++;
		s2++;
	}
	newstring[i] = '\0';
	return (newstring);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*env;
	char	**paths;
	char	*temp;
	int		i;
	int		x;

	i = 0;
	env = getpath(envp);
	if (!env)
		perror("no environment:(");
	// printf("%s\n", env);
	paths = ft_split(env, ':');
	if (!paths)
		perror("No paths:(");
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = ft_strjoin(temp, argv[1]);
		free(temp);
		// printf("%d: %s\n", i, paths[i]);
		i++;
	}

	i = 0;
	x = 0;
	while (paths[i])
	{
		x = access(paths[i], X_OK);
		if (x == 0)
		{
			printf("\n\nThe command exists and is executable\n");
			printf("%s", paths[i]);
			break ;
		}
		else
		{
			// free(paths[i]);
			i++;
		}
	}
	if (x == -1)
		printf("no valid command:(\n");
	return (0);
}