/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:42:13 by mmisumi           #+#    #+#             */
/*   Updated: 2025/01/29 21:09:45 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	main(int argc, char *argv[])
// {
// 	char	cmd[] = "/bin/cat";

// 	if (execve(cmd, argv, NULL) == -0)
// 		printf("succesfull");
// 	else
// 		return -1;

// }

// int	main(int argc, char *argv[], char *envp[])
// {
// 	char	*path;
// 	int		i;
// 	int		len;

// 	i = 0;
// 	while (envp[i])
// 	{
// 		path = ft_strnstr(envp[i], "PATH", 4);
// 		if (path != NULL)
// 			return(path += 5);
// 		i++;
// 	}
// 	return (-1);
// }

int	main(int argc, char *argv[])
{
	int		pipefd[2];
	pid_t	cpid1;//child id
	pid_t	cpid2;


	// if (pipefd == -1)
	// {
	// 	perror("pipe failed");
	// 	return -1;
	// }
	cpid1 = fork();//fork the first child(for first command)
	if (cpid1 == 0)
	{
		close(pipefd[0]);//close unused read end of pipe
		dup2(pipefd[1], STDOUT_FILENO);//make output go to pipe
		execve(argv[1], &argv[1], NULL);
		close(pipefd[1]);
	}
	else
	{
		perror("fork failed");
		return -1;
	}
	cpid2 = fork();//for the second child(second command)
	if (cpid2 == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		execve(argv[2], &argv[2], NULL);
		close(pipefd[0]);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(cpid1, NULL, 0);
	waitpid(cpid2, NULL, 0);
	//wait(NULL);//wait for the first child
	//wait(NULL);//wait for the second child

	return (0);
}