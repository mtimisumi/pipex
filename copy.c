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
	paths = get_path(path, cmd);
	while (paths[i])
	{
		if (access(paths[i], R_OK) == 0)
			return (paths[i]) ;
		else
		{
			free(paths[i]);//set path to null??
			i++;
		}
	}
	return (NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		file1;
	int		file2;
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd;
	char	**cmd_args;
	int		pip[2];

	if (argc != 5)
		return (-1);
	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		return (-1);
	dup2(file1, STDIN_FILENO);
	close(file1);
	pipe(pip);
	pid1 = fork();
	if (pid1 == -1)
		return (-1);
	if (pid1 == CHILD)
	{
		close(pip[READ]);
		dup2(pip[WRITE], STDOUT_FILENO);
		close(pip[WRITE]);
		cmd_args = ft_split(argv[2], ' ');
		cmd = get_cmd(cmd_args[0], envp);
		if (cmd != NULL)
			execve(cmd, cmd_args, envp);
		else
			perror("cmd1 fail");
		exit(1);
	}
	pid2 = fork();
	if (pid1 == -1)
		return (-1);
	if (pid2 == CHILD)
	{
		file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file2 == -1)
			exit (1);
		dup2(file2, STDOUT_FILENO);
		close(file2);
		close(pip[WRITE]);
		dup2(pip[READ], STDIN_FILENO);
		close(pip[READ]);
		cmd_args = ft_split(argv[3], ' ');
		cmd = get_cmd(cmd_args[0], envp);
		if (cmd != NULL)
			execve(cmd, cmd_args, envp);
		else
			perror("cmd2 fail");
		exit(1);
	}
	wait(NULL);
	close (pip[READ]);
	close (pip[WRITE]);
	return (0);
}
