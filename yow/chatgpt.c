// #include "pipex.h"

// char	*getpath(char **argv, char **envp)
// {
// 	char	*env = NULL;
// 	char	**paths;
// 	char	*temp;
// 	int		i;
// 	int		x;

// 	i = 0;
// 	while (envp[i])
// 	{
// 		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
// 		{
// 			env = envp[i] + 5;
// 			break;
// 		}
// 		i++;
// 	}
// 	printf("env: %s\n", env);
// 	if (!env)
// 	{
// 		perror("no environment...");
// 		return (NULL);
// 	}

// 	paths = ft_split(env, ':');
// 	if (!paths)
// 	{
// 		perror("no paths...");
// 		return (NULL);
// 	}

// 	i = 0;
// 	while (paths[i])
// 	{
// 		temp = ft_strjoin(paths[i], "/");
// 		free(paths[i]);
// 		paths[i] = ft_strjoin(temp, argv[1]);
// 		free(temp);
// 		i++;
// 	}

// 	i = 0;
// 	while (paths[i])
// 	{
// 		if (access(paths[i], X_OK) == 0)
// 		{
// 			printf("Access successful: %s\n", paths[i]);
// 			return (paths[i]); // ✅ Fix: Don't return NULL prematurely
// 		}
// 		free(paths[i]); // ✅ Free unused memory
// 		i++;
// 	}

// 	printf("No valid command found\n");
// 	free(paths);
// 	return (NULL);
// }

// int	main(int argc, char *argv[], char *envp[])
// {
// 	if (argc < 2)
// 	{
// 		printf("no arguments");
// 		return (-1);
// 	}

// 	char	*cmd = getpath(argv, envp);
// 	if (!cmd)
// 	{
// 		printf("Command not found\n");
// 		return (1);
// 	}

// 	printf("Executing: %s\n", cmd);

// 	char	**array = ft_split(cmd, ' ');
// 	int		i = 0;
// 	while (array[i])
// 	{
// 		printf("array[%d]: %s\n", i, array[i]);
// 		i++;
// 	}

// 	// ✅ Execute the command
// 	execve(cmd, array, envp);

// 	// If execve fails:
// 	perror("execve failed");
// 	return (1);
// }
