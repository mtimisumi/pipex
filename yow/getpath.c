/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:29:39 by mmisumi           #+#    #+#             */
/*   Updated: 2025/02/01 19:51:17 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*getpath(char **argv, char **envp)
{
	char	*env;
	char	**paths;
	char	*temp;
	int		i;
	int		x;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5)== 0)
		{
			env = envp[i] += 5;
			break ;
		}
		i++;
	}
	printf("env: %s", env);
	if (!env)
	{
		perror("no environment...");
		return (NULL);
	}
	paths = ft_split(env, ':');
	if (!paths)
	{
		perror("no paths...");
		return (NULL);
	}
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = ft_strjoin(temp, argv[1]);
		free(temp);
		i++;
	}
	i = 0;
	x = 0;
	while (paths[i])
	{
		x = access(paths[i], X_OK);
		if (x == 0)
		{
			printf("acces is succesful");
			return (paths[i]);
		}
		else if (x == -1)
		{
			perror("no valid command...");
			return (NULL);
		}
		else
		{
			free(paths[i]);
			paths[i] = NULL;
			i++;
		}
	}
	printf("something went wrong");
	free(paths);
	paths = NULL;
	return (NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd;

	cmd = getpath(argv, envp);
	printf("command: %s", cmd);
	return (0);
}

