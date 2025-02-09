// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pipex.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/09 14:45:54 by mmisumi           #+#    #+#             */
// /*   Updated: 2025/02/09 17:45:43 by mmisumi          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "pipex.h"

// #define CHILD 0
// #define READ 0
// #define WRITE 1

// char	*get_env(char **envp)
// {
// 	char	*env;
// 	int		i;

// 	i = 0;
// 	while(envp[i])
// 	{
// 		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
// 		{
// 			env = envp[i] + 5;
// 			printf("env: %s\n", env);
// 			if (! env)
// 				perror("1");
// 			break ;
// 		}
// 		i++;
// 	}
// 	return (env);
// }

// char	**get_path(char *path, char *cmd)
// {
// 	char	**paths;
// 	char	*temp;
// 	int		i;

// 	i = 0;
// 	paths = ft_split(path, ':');
// 	while (paths[i])
// 	{
// 		temp = ft_strjoin(paths[i], "/");
// 		free(paths[i]);
// 		paths[i] = ft_strjoin(temp, cmd);
// 		free(temp);
// 		i++;
// 	}
// 	return (paths);
// }

// char	*get_cmd(char *argv, char **envp)
// {
// 	char	*path;
// 	char	**cmd;
// 	char	**paths;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	path = get_env(envp);
// 	printf("path: %s\n", path);
// 	printf("argv: %s\n", argv);
// 	paths = get_path(path, cmd[0]);
// 	while (paths[i])
// 	{
// 		printf("paths[%d]: %s\n", i, paths[i]);
// 		if (access(paths[i], R_OK) == 0)
// 		{
// 			printf("command: %s exists and is readable\n", paths[i]);
// 			return (paths[i]) ;
// 		}
// 		else
// 		{
// 			free(paths[i]);
// 			i++;
// 		}
// 	}
// 	return (NULL);
// }


// int	main(int argc, char *argv[], char *envp[])
// {
// 	char	*cmd;
// 	char	**cmd_args;
// 	int		file1;
// 	pid_t	pid1;

// 	file1 = open(argv[1], O_RDONLY);
// 	dup2(file1, STDIN_FILENO);
// 	close (file1);
// 	pid1 = fork();
// 	if (pid1 == CHILD)
// 	{
// 		cmd_args = ft_split(argv[2], ' ');
// 		printf("cmd_arg[0]: %s\n", cmd_args[0]);
// 		printf("cmd_arg[1]: %s\n", cmd_args[1]);
// 		printf("cmd_arg[2]: %s\n", cmd_args[2]);
// 		cmd = get_cmd(cmd_args[0], envp);
// 		exit(0);
// 	}







// 	// cmd = get_cmd(argv[1], envp);
// 	// printf("cmd1: %s\n", cmd);
// 	// cmd = get_cmd(argv[2], envp);
// 	// printf("cmd2: %s\n", cmd);
// 	return (0);
// }
