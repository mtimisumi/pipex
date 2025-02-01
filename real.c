/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:29:43 by mmisumi           #+#    #+#             */
/*   Updated: 2025/02/01 19:52:09 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd;
	int		pipefd[2];
	pid_t	cpid1;//child id
	pid_t	cpid2;

	fd = open(argv[1], O_RDWR);
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



