/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:26:10 by mmisumi           #+#    #+#             */
/*   Updated: 2025/02/09 14:01:36 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>

size_t		ft_strlen(const char *s);
int 		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
static int	word_count(char const *s, char c);
char		**free_array(char **arr, int x);
char		**litsplit(char **arr, char const *s, char c);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*get_env(char **argv, char **envp);
char		**get_path(char *path, char **cmd);
char		*get_cmd(char **argv, char **envp);

#endif