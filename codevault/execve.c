/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:42:13 by mmisumi           #+#    #+#             */
/*   Updated: 2025/01/28 17:34:19 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	main(int argc, char *argv[], char *envp[])
// {
// 	char	**curr = envp;
// 	int		envp_count = 1;

// 	printf("Accessing environment variables with getenv:\n");
// 	printf("	USER=%s\n", getenv("USER"));
// 	printf("	HOME=%s\n", getenv("HOME"));
// 	printf("	UNDEFINED=%s\n", getenv("UNDEFINED"));
// 	printf("	TERM=%s\n", getenv("TERM"));

// 	printf("\n Contents of envp:\n");
// 	while (*curr != NULL)
// 	{
// 		printf("	%s\n", *curr);
// 		curr++;
// 		envp_count++;
// 	}
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	char	cmd[] = "/bin/cat";

	if (execve(cmd, &argv[1], NULL) == -0)
		printf("succesfull");
	else
		return -1;

}


// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;
// 	i = 0;
// 	if (s == NULL)
// 		return (0);
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// int ft_strlcpy(char *dst, const char *src, size_t size)
// {
//     size_t  i;
//     size_t  len;
//     len = ft_strlen(src);
//     i = 0;
//     if (size == 0)
//         return (len);
//     while (src[i] != '\0' && i < size - 1)
//     {
//         dst[i] = src[i];
//         i++;
//     }
//     dst[i] = '\0';
//     return (len);
// }

// char    *ft_strdup(const char *s)
// {
//     char    *ptr;
//     int     len;
//     len = ft_strlen(s);
//     ptr = malloc(len * sizeof(char) + 1);
//     if (ptr == NULL)
//         return (NULL);
//     ft_strlcpy(ptr, s, len + 1);
//     return (ptr);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		i;
// 	char	*newstring;

// 	if (s1 == NULL)
// 		return (ft_strdup(s2));
// 	if (s2 == NULL)
// 		return (ft_strdup(s1));
// 	newstring = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (newstring == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (*s1)
// 	{
// 		newstring[i] = *s1;
// 		i++;
// 		s1++;
// 	}
// 	while (*s2)
// 	{
// 		newstring[i] = *s2;
// 		i++;
// 		s2++;
// 	}
// 	newstring[i] = '\0';
// 	return (newstring);
// }

// int	main(int argc, char *argv[], char *envp[])
// {
// 	const char	*str = "/bin/";
// 	char	*cmd;
	
// 	cmd = ft_strjoin(str, argv[2]);//path to shell command

// 	//check if command is an executable
// 	if (access(cmd, X_OK) == 0)
// 		printf("The command exists and is executable\n");
// 	else
// 		perror("The command is not found or is not executable\n");

// 	if (execve(cmd, &argv[2], envp) == 0)
// 		printf("execve succesful");
// 	else
// 		perror("execve unsuccesful");
// 	return(0);
// }