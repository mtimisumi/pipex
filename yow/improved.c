/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improved.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:29:39 by mmisumi           #+#    #+#             */
/*   Updated: 2025/02/04 19:16:04 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*getpath(char **argv, char **envp)
{
	char	*env = NULL;
	char	**paths;
	char	*temp;
	int		i = 0;
	char	**x;

	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5)== 0)
		{
			env = envp[i] + 5;
			break ;
		}
		i++;
	}
	printf("env: %s\n", env);
	if (!env)
	{
		perror("no environment...\n");
		return (NULL);
	}
	paths = ft_split(env, ':');
	if (!paths)
	{
		perror("no paths...\n");
		return (NULL);
	}
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		x = ft_split(argv[1], ' ');
		paths[i] = ft_strjoin(temp, x[0]);
		free(temp);
		i++;
	}
	i = 0;
	while (paths[i])
	{
		if (access(paths[i], X_OK)== 0)
		{
			printf("acces is succesful\n");
			return (paths[i]);
		}
		free(paths[i]);
		i++;
	}
	printf("something went wrong\n");
	free(paths);
	// paths = NULL;
	return (NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd;
	int	i = 0;
	char **x;

	cmd = getpath(argv, envp);
	if (!cmd)
	{
		printf("Command not found\n");
		return (-1);
	}
	printf("command: %s\n", cmd);
	char	**array = ft_split(cmd, ' ');
	while (array[i])
	{
		printf("array[%d] %s\n", i, array[i]);
		i++;
	}
	x = ft_split(argv[1], ' ');

	open("yo", O_RDONLY);
	fork();
	execve(cmd, &x[1], envp);
	return (0);
}

