#include "pipex.h"

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
			if (! env)
				perror(1);
			break ;
		}
		i++;
	}
	printf("envp[i]: %s\n", envp[i]);
	return (env);
}

char	*getpath(char *path, char **cmd)
{

}

int	main(int argc, char *argv[], char *envp[])
{
	char	*path;
	char	**cmd;
	int		i;

	i = 0;
	path = get_env(argv, envp);
	cmd = ft_split(argv[2], ' ');
	while (cmd[i])
	{
		printf("%s\n", cmd[i]);
		i++;
	}
	getpath(path, cmd);
}
