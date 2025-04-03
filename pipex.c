// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pipex.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/10 17:14:26 by mmisumi           #+#    #+#             */
// /*   Updated: 2025/04/03 15:53:09 by mmisumi          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "pipex.h"

#define CHILD 0
#define READ 0
#define WRITE 1

char	*get_env(char **envp)
{
	char	*env = NULL;
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

	if (cmd[0] == '/' || cmd[0] == '.')
	{
		return (cmd);
	}


	i = 0;
	path = get_env(envp);
	paths = get_path(path, cmd);
	while (paths[i])
	{
		if (access(paths[i], R_OK) == 0)
			return (paths[i]);
		else
			i++;
	}
	return (NULL);
}

// int	main(int argc, char *argv[], char *envp[])
// {
// 	int		file1;
// 	int		file2;
// 	pid_t	pid1;
// 	pid_t	pid2;
// 	char	*cmd;
// 	char	**cmd_args;
// 	int		pip[2];

// 	if (argc != 5)
// 	{
// 		printf("no goo amount of arguments");
// 		return (0);
// 	}
// 	logger("argc: %d", argc);
// 	file1 = open(argv[1], O_RDONLY);
// 	if (file1 == -1)
// 	{
// 		printf("no valid file");
// 		return (0);
// 	}
// 	dup2(file1, STDIN_FILENO);
// 	close(file1);
// 	pipe(pip);
// 	pid1 = fork();
// 	if (pid1 == -1)
// 	{
// 		printf("forking pid1 failed");
// 		return (0);
// 	}

// 	//childprocess 1
// 	if (pid1 == CHILD)
// 	{
// 		logger("pid1 forked");
// 		close(pip[READ]);
// 		dup2(pip[WRITE], STDOUT_FILENO);
// 		close(pip[WRITE]);
// 		cmd_args = ft_split(argv[2], ' ');
// 		cmd = get_cmd(cmd_args[0], envp);
		
// 		if (cmd != NULL)
// 		{
// 			logger("cmd1: %s", cmd);
// 			if (execve(cmd, cmd_args, envp) == -1)
// 				exit(1);
// 		}
// 		logger("execve1 fail");
// 		// else
// 			// free_array();
// 		exit(1);
// 	}

// 	pid2 = fork();
// 	if (pid2 == -1)
// 	{
// 		printf("forking pid1 failed");
// 		return (0);
// 	}

// 	//childprocess 2
// 	if (pid2 == CHILD)
// 	{
// 		// printf("232132");
// 		logger("pid2 forked");
// 		file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 		if (file2 == -1)
// 		{
// 			printf("something went wrong with file2");
// 			exit (1);
// 		}
// 		dup2(file2, STDOUT_FILENO);
// 		close(file2);
// 		close(pip[WRITE]);
// 		dup2(pip[READ], STDIN_FILENO);
// 		close(pip[READ]);
// 		cmd_args = ft_split(argv[3], ' ');
// 		cmd = get_cmd(cmd_args[0], envp);
// 		if (cmd != NULL)
// 		{
// 			logger("cmd2: %s", cmd);
// 			if (execve(cmd, cmd_args, envp) == -1)
// 			{
// 				perror("cmd2 fail");
// 				exit(127);
// 			}
// 			logger("execve2 fail");
// 		// else
// 		}
// 			// free_array();

// 		exit(1);
// 	}
// 	wait(NULL);

// 	int	status = 77;
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, &status, 0);

// 	int	exitcode = 0;
// 	if (WIFEXITED(status))
// 	{
// 		exitcode = WEXITSTATUS(status);
// 		printf("exitcode: %d\n", exitcode);
// 	close (pip[READ]);
// 	close (pip[WRITE]);
// 	return (exitcode);
// }
// }


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
    {
        printf("no good amount of arguments\n");
        return (0);
    }
    logger("argc: %d", argc);

    // Open input file
    file1 = open(argv[1], O_RDONLY);
    if (file1 == -1)
    {
        perror("Error opening infile");
        return (1);
    }

    // Create pipe
    if (pipe(pip) == -1)
    {
        perror("Error creating pipe");
        return (1);
    }

    // Fork first child process
    pid1 = fork();
    if (pid1 == -1)
    {
        perror("Error forking pid1");
        return (1);
    }

    if (pid1 == CHILD)
    {
        // Child Process 1
        logger("pid1 forked");
        dup2(file1, STDIN_FILENO); // Redirect infile to stdin
        close(file1);
        close(pip[READ]);         // Close unused read end of the pipe
        dup2(pip[WRITE], STDOUT_FILENO); // Redirect stdout to pipe write end
        close(pip[WRITE]);

        cmd_args = ft_split(argv[2], ' ');
        cmd = get_cmd(cmd_args[0], envp);
        if (cmd != NULL)
        {
            logger("cmd1: %s", cmd);
            if (execve(cmd, cmd_args, envp) == -1)
            {
                perror("Error executing cmd1");
                exit(1);
            }
        }
        logger("execve1 fail");
        exit(1);
    }

    // Close unused file descriptor in parent
    close(file1);
    close(pip[WRITE]); // Close write end of the pipe in parent

    // Fork second child process
    pid2 = fork();
    if (pid2 == -1)
    {
        perror("Error forking pid2");
        return (1);
    }

    if (pid2 == CHILD)
    {
        // Child Process 2
        logger("pid2 forked");
        file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (file2 == -1)
        {
            perror("Error opening outfile");
            exit(1);
        }
        dup2(pip[READ], STDIN_FILENO); // Redirect pipe read end to stdin
        close(pip[READ]);
        dup2(file2, STDOUT_FILENO);    // Redirect stdout to outfile
        close(file2);

        cmd_args = ft_split(argv[3], ' ');
        cmd = get_cmd(cmd_args[0], envp);
		logger("cmd2: %s", cmd);
		int result = check_file_permissions(cmd, HAS_EXEC | HAS_READ | HAS_WRITE);
		if (result == ERR_NO_FILE)
		{
			perror("Error: File does not exist");
			exit(127);
		}
		else if (result == ERR_NO_PERM)
		{
			perror("Error: No execute permission");
			exit(126);
		}
        if (cmd != NULL)
        {
            logger("cmd2: %s", cmd);
            if (execve(cmd, cmd_args, envp) == -1)
            {
                perror("Error executing cmd2");
                exit(127);
            }
        }
        logger("execve2 fail");
        exit(1);
    }

    // Close unused pipe read end in parent
    close(pip[READ]);

    // Wait for child processes to finish
    // waitpid(pid1, NULL, 0);
    // waitpid(pid2, NULL, 0);

		int status = 0;
	 // Wait for child processes to finish
	 waitpid(pid1, NULL, 0); // Wait for the first child
	 waitpid(pid2, &status, 0); // Wait for the second child and capture its status
 
	 // Check and print the exit code of the last child
	 if (WIFEXITED(status))
	 {
		 int exit_code = WEXITSTATUS(status);
		 logger("Last child exited with code: %d", exit_code);
		 printf("Last child exited with code: %d\n", exit_code);
		 return (exit_code);
	 }
 
	 return (status);

    return (0);
}