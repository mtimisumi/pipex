/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:15:21 by mmisumi           #+#    #+#             */
/*   Updated: 2025/02/05 17:02:13 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define READ 0
#define WRITE 1

int	main(int agrc, char *argv[], char *envp[])
{
	int	fd;
	int	child1;
	int	child2;
	int	pipe1[2];//0 for read, 1 for write to connect cmd 1 stdout to cmd 2 stdin
	int	pipe2[2];//second to connect cmd 2 stdout as stdin for outfile (or we do it with dup2?)

	fd = open("text.txt", O_RDONLY);//opens argv[1] which should be a file
	dup2(fd, STDIN_FILENO);//changes the stdin to have the file as stdin
	close(fd);//closes fd since stdin has been assigned
	pipe(pipe1);
	child1 = fork();
	if (child1 == 0)
	{
		close(pipe1[READ]);//close unused read end of the pipe
		dup2(pipe1[WRITE], STDOUT_FILENO);//redirect stdout to write end of the pipe
		close(pipe1[WRITE]);//close original write end
		char	*args[] = {"/usr/bin/ls", "-l", NULL};
		execve(args[0], args, NULL);//we will use our path and args from acces and envp
	}
	pipe(pipe2);
	child2 = fork();
	if (child2 == 0)
	{
		close(pipe2[WRITE]);//close unused write end of pipe
		dup2(pipe2[READ], STDIN_FILENO);//redirect stdin to read end of pipe
		close(pipe2[READ]);//clse original read end
		char	*args[] = {"/usr/bin/wc", "-l", NULL};
		execve(args[0], args, NULL);
	}
	//parent process
	close(pipe1[READ]);//close both ends of pipe
	close(pipe1[WRITE]);
	close(pipe2[READ]);
	close(pipe2[WRITE]);
	//wait for both child proccesses to finish
	wait(NULL);
	wait(NULL);
	return (0);
}
