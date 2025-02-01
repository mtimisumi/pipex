/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:41:37 by mmisumi           #+#    #+#             */
/*   Updated: 2025/02/01 19:33:04 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

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
