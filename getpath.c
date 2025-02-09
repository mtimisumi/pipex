#include "pipex.h"

#define CHILD 0
#define READ 0
#define WRITE 1

char	*get_env(char **argv, char **envp)
{
	char	*env;
	int		i;

	i = 0;
	while(envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			env = envp[i] + 5;
			printf("env: %s\n", env);
			if (! env)
				perror("1");
			break ;
		}
		i++;
	}
	return (env);
}

char	**get_path(char *path, char **cmd)
{
	char	**paths;
	char	*temp;
	int		i;

	i = 0;
	paths = ft_split(path, ':');
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = ft_strjoin(temp, cmd[0]);
		free(temp);
		i++;
	}
	return (paths);
}

char	*get_cmd(char ** cmd, char **argv, char **envp)
{
	char	*path;
	// char	**cmd;
	char	**paths;
	int		i;
	int		j;

	i = 0;
	j = 0;
	path = get_env(argv, envp);
	printf("path: %s\n", path);
	// cmd = ft_split(argv[2], ' ');
	while (cmd[j])
	{
		printf("cmd[%d} %s\n", j, cmd[j]);
		j++;
	}
	paths = get_path(path, cmd);
	while (paths[i])
	{
		printf("paths[%d]: %s\n", i, paths[i]);
		if (access(paths[i], R_OK) == 0)
		{
			printf("command: %s exists and is readable\n", paths[i]);
			return (paths[i]) ;
		}
		else
		{
			free(paths[i]);
			i++;
		}
	}
	return (NULL);
}

// char	*execve_cmd()
// {

// }

int	main(int argc, char *argv[], char *envp[])
{
	int		fd;
	pid_t	pid1;
	char	*cmd;
	char	**args;

	// if (argc != 5)
	// {
	// 	printf("no goo amount of arguments");
	// 	return (0);
	// }
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("no valid file");
		return (0);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	pid1 = fork();
	if (pid1 == -1)
	{
		printf("forking pid1 failed");
		return (0);
	}
	printf("argv[2]: %s\n", argv[2]);
	args = ft_split(argv[2], ' ');
	if (pid1 == CHILD)
	{
		cmd = get_cmd(args, argv, envp);
		if (cmd != NULL)
		{
			execve(cmd, args, envp);
			printf("cmd: %s\n", cmd);
			printf("args[0]: %s\n", args[0]);
			printf("args[1]: %s\n", args[1]);
			printf("args[2]: %s\n", args[2]);
		}
	}
	// cmd = get_cmd(argv, envp);
	// printf("cmd: %s\n", cmd);
	return (0);
}
