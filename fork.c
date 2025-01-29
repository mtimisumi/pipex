/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:11:32 by mmisumi           #+#    #+#             */
/*   Updated: 2025/01/26 14:31:13 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[2])
{
	int	id;

	id = fork();
	// printf("Hello World\n");//output will be two Hello Worlds, one of main program, one of child created
	// printf("Hello World from id: %d\n", id);//child id process will be 0, other is from parent process
	if (id == 0)
		printf("Hello from child process\n");
	else
		printf("Hello from the main process\n");
	return (0);
}

int	main(int argc, char *argv[2])
{
	int	id;

	id = fork();
	if (id != 0)//this will make sure only the main process will be forked
		fork();
	printf("Hello World\n");//will be printed four times cause when fork is called previous forks will fork too

	return (0);
}
