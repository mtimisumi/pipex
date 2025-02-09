// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   execve.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/27 22:42:13 by mmisumi           #+#    #+#             */
// /*   Updated: 2025/01/29 18:17:30 by mmisumi          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "pipex.h"

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

// int	main(int argc, char *argv[])
// {
// 	char	cmd[] = "/bin/cat";

// 	if (execve(cmd, argv, NULL) == -0)
// 		printf("succesfull");
// 	else
// 		return -1;

// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substr;
// 	size_t	i;
// 	size_t	j;
// 	size_t	strlen;

// 	strlen = ft_strlen(s);
// 	i = start;
// 	j = 0;
// 	if (start >= strlen)
// 		return (ft_strdup(""));
// 	if (start + len > strlen)
// 		len = strlen - start;
// 	substr = (char *)malloc((len + 1) * sizeof(char));
// 	if (substr == NULL)
// 		return (NULL);
// 	while (j < len)
// 	{
// 		substr[j] = s[i];
// 		i++;
// 		j++;
// 	}
// 	substr[j] = '\0';
// 	return (substr);
// }

// char	*ft_strnstr(const char *big, const char *lit, size_t len)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	if (lit[0] == '\0')
// 		return ((char *)big);
// 	while (big[i] && len > 0)
// 	{
// 		if (big[i] != lit[j])
// 		{
// 			i++;
// 			len--;
// 		}
// 		if (big[i] == lit[j])
// 		{
// 			while ((big[i + j] == lit[j]) && lit[j] != '\0' && len-- > 0)
// 				j++;
// 			if (lit[j] == '\0')
// 				return ((char *)&big[i]);
// 			reset(&i, &j, &len);
// 		}
// 	}
// 	return (NULL);
// }

// int	main(int argc, char *argv[], char *envp[])
// {
// 	char	*path;
// 	int		i;
// 	int		len;

// 	i = 0;
// 	while (envp[i])
// 	{
// 		path = ft_strnstr(envp[i], "PATH", 4);
// 		if (path != NULL)
// 			return(path += 5);
// 		i++;
// 	}
// 	return (-1);
// }


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