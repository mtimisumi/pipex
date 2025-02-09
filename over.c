// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   over.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/05 16:15:21 by mmisumi           #+#    #+#             */
// /*   Updated: 2025/02/09 13:44:33 by mmisumi          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "pipex.h"

// #define CHILD 0

// #define READ_END 0
// #define WRITE_END 1

// int	main(int agrc, char *argv[], char *envp[])
// {
// 	// pid_t pid = getpid();  // Get the process ID
//     // printf("Process ID: %d\n", pid);
// 	int	fd;
// 	pid_t	pid1;
// 	pid_t	pid2;
// 	int	pipe1[2];//0 for read, 1 for write to connect cmd 1 stdout to cmd 2 stdin

// 	// check permissions
// 	fd = open("/dev/urandom", O_RDONLY);//opens argv[1] which should be a file
// 	if (fd == -1)
// 	{
// 		perror("1");
// 		exit(1);
// 	}
// 	dup2(fd, STDIN_FILENO);//changes the stdin to have the file as stdin
// 	close(fd);//closes fd since stdin has been assigned
// 	pipe(pipe1);
// 	pid1 = fork();
// 	if (pid1 == -1)
// 	{

// 	}
// 	if (pid1 == CHILD)
// 	{
// 		close(pipe1[READ_END]);//close unused read end of the pipe
// 		dup2(pipe1[WRITE_END], STDOUT_FILENO);//redirect stdout to write end of the pipe
// 		close(pipe1[WRITE_END]);//close original write end
// 		char	*args[] = {"/usr/bin/cat", NULL};
// 		execve(args[0], args, NULL);//we will use our path and args from acces and envp
// 		perror("");
// 		exit(1);
// 	}
// 	// pipe(pipe2);
// 	pid2 = fork();
// 	if (pid2 == 0)
// 	{
// 		// check if permissions
// 		int fd = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 		if (fd == -1)
// 		{
// 			perror("2");
// 			exit(1);
// 		}
// 		dup2(fd, STDOUT_FILENO);
// 		close(fd);
// 		close(pipe1[WRITE_END]);
// 		dup2(pipe1[READ_END], STDIN_FILENO);//redirect stdout to write end of the pipe
// 		close(pipe1[READ_END]);//close original write end
// 		char	*args[] = {"/usr/bin/head", "-3", NULL};
// 		execve(args[0], args, NULL);
// 		perror("");
// 		exit(1);
// 	}
// 	//parent process
// 	close(pipe1[READ_END]);//close both ends of pipe
// 	close(pipe1[WRITE_END]);
// 	//wait for both child proccesses to finish
// 	// wait(&pid1);
// 	// waitpid()

// 	wait(NULL);
// 	// int status;
//     //     waitpid(pid1, &status, 0); // Wait for the specific child
//     //     printf("Parent: Child (PID %d) exited\n", pid1);

// 	return (0);
// }
