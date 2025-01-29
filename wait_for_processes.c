/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_processes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:59:25 by mmisumi           #+#    #+#             */
/*   Updated: 2025/01/26 14:31:13 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//we will check whether we are in the main process(6-10) childe process(1-5)
int	main(int argc, char *argv[])
{
	int	id;
	int	n;
	int	i;

	id = fork();
	if (id == 0)
		n = 1;
	else
		n = 6;
	if (id != 0)
		wait(NULL);//so it will wait for the child process to terminate
	i = n;
	while(i < n + 5)
	{
		printf("%d\n", i);
		i++;
	} 
	return (0);
}