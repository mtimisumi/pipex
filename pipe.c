// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pipe.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/12 14:34:47 by mmisumi           #+#    #+#             */
// /*   Updated: 2025/01/27 22:32:32 by mmisumi          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "pipex.h"

// int	main(int argc, char *argv[])
// {
// 	int	fd[2];//fd[0] = read end, fd[1] = write end
// 	int	id;
// 	int	x;
// 	int	y;

// 	if (pipe(fd))//creates the pipe and has the two "keys" to that pipe
// 	{
// 		printf("An error occured with opening the pipe\n");
// 		return (-1);
// 	}
// 	id = fork();
// 	if (id == -1)
// 		return (-1);
// 	if (id == 0)//child process
// 	{
// 		close (fd[0]);
// 		printf("Input a number: ");
// 		scanf("%d", &x);
// 		if (write(fd[1], &x, sizeof(int)) == -1)
// 			return (-1);
// 		close (fd[1]);
// 	}
// 	else//parent process
// 	{
// 		close (fd[1]);
// 		if (read(fd[0], &y, sizeof(int)) == -1)
// 			return (-1);
// 		close (fd[0]);
// 		printf("Got from childprocess: %d\n", y);
// 	}
// 	return (0);
// }

// int	main(int argc, char *argv[])
// {
// 	int	fd[2];
// 	int	pid1;

// 	if (pipe(fd) == -1)
// 		return (-1);
// 	pid1 = fork();
// 	if (pid1 == -1)
// 		return (-1);
// 	if (pid1 == 0)//in child process
// 	{
// 		execlp;//we should use execve instead to get to commands via path
// 	}
// 	waitpid(pid1, NULL, 0);
// 	return (0);
// }