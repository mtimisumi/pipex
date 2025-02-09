#include "pipex.h"

#define CHILD 0
#define READ 0
#define WRITE 1

char	*get_env(char **envp)
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

char	**get_path(char *path, char *cmd)
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
		paths[i] = ft_strjoin(temp, cmd);
		free(temp);
		i++;
	}
	return (paths);
}

char	*get_cmd(char *cmd, char **envp)
{
	char	*path;
	char	**paths;
	int		i;
	int		j;

	i = 0;
	j = 0;
	path = get_env(envp);
	printf("path: %s\n", path);
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

int	main(int argc, char *argv[], char *envp[])
{
	int		fd;
	char	*cmd;
	char	**cmd_args;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("no");
		return (0);
	}
	dup2(fd, STDIN_FILENO);
	cmd_args = ft_split(argv[2], ' ');
	printf("cmd_arg[0]: %s\n", cmd_args[0]);
	printf("cmd_arg[1]: %s\n", cmd_args[1]);
	printf("cmd_arg[2]: %s\n", cmd_args[2]);
	cmd = get_cmd(cmd_args[0], envp);
	if (cmd == NULL)
		printf("no good command");
	else
		printf("yay worked");
	return (0);
}
