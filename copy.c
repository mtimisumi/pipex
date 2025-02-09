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

// char	*get_cmd(char *cmd, char **envp)
// {
// 	char	*path;
// 	char	**paths;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	path = get_env(envp);
// 	printf("path: %s\n", path);
// 	paths = get_path(path, cmd);
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
// 	int		file1;
// 	int		file2;
// 	char	*cmd;
// 	char	**cmd_args;
// 	pid_t	pid1;
// 	pid_t	pid2;
// 	int		pip[2];

// 	file1 = open(argv[1], O_RDONLY);
// 	if (file1 == -1)
// 	{
// 		printf("no");
// 		return (0);
// 	}
// 	dup2(file1, STDIN_FILENO);
// 	pid1 = fork();
// 	if (pid1 == 0)
// 	{
// 		cmd_args = ft_split(argv[2], ' ');
// 		printf("cmd_arg[0]: %s\n", cmd_args[0]);
// 		printf("cmd_arg[1]: %s\n", cmd_args[1]);
// 		printf("cmd_arg[2]: %s\n", cmd_args[2]);
// 		cmd = get_cmd(cmd_args[0], envp);
// 		if (cmd == NULL)
// 			printf("no good command\n");
// 		else
// 			printf("yay worked\n");
// 		execve(cmd, cmd_args, envp);
// 		exit(0);
// 	}

// 	return (0);
// }
