// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   old.c                                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/29 13:32:25 by mmisumi           #+#    #+#             */
// /*   Updated: 2025/01/29 19:10:07 by mmisumi          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "pipex.h"
// #include <string.h>

// char	*getpath(char **envp)
// {
// 	int		i;

// 	i = 0;
// 	while (envp[i])
// 	{
// 		if (strncmp(envp[i], "PATH=", 5)== 0)
// 			return (envp[i] += 5);
// 		i++;
// 	}
// 	return (NULL);
// }

// int	main(int argc, char *argv[], char *envp[])
// {
// 	char	*env;
// 	char	**paths;
// 	char	*temp;
// 	int		i;
// 	int		x;

// 	i = 0;
// 	env = getpath(envp);
// 	if (!env)
// 		perror("no environment:(");
// 	// printf("%s\n", env);
// 	paths = ft_split(env, ':');
// 	if (!paths)
// 		perror("No paths:(");
// 	while (paths[i])
// 	{
// 		temp = ft_strjoin(paths[i], "/");
// 		free(paths[i]);
// 		paths[i] = ft_strjoin(temp, argv[1]);
// 		free(temp);
// 		// printf("%d: %s\n", i, paths[i]);
// 		i++;
// 	}

// 	i = 0;
// 	x = 0;
// 	while (paths[i])
// 	{
// 		x = access(paths[i], X_OK);
// 		if (x == 0)
// 		{
// 			printf("\n\nThe command exists and is executable\n");
// 			printf("%s", paths[i]);
// 			break ;
// 		}
// 		else
// 		{
// 			// free(paths[i]);
// 			i++;
// 		}
// 	}
// 	if (x == -1)
// 		printf("no valid command:(\n");
// 	return (0);
// }