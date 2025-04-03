/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:26:10 by mmisumi           #+#    #+#             */
/*   Updated: 2025/04/03 16:22:51 by mmisumi          ###   ########.fr       */
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

size_t	ft_strlen(const char *s);
int 	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**free_array(char **arr, int x);
char	**litsplit(char **arr, char const *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_cmd(char *argv, char **envp);
char	**get_path(char *path, char *cmd);
char	*get_env(char **envp);

void logger(const char *format, ...);
#define HAS_READ  0x01 // Flag for read permission
#define HAS_WRITE 0x02 // Flag for write permission
#define HAS_EXEC  0x04 // Flag for execute permission
int check_file_permissions(const char *path, int flags);
#define ERR_NO_FILE   -1 // Error code for file not existing
#define ERR_NO_PERM   -2 // Error code for lacking permissions
#define SUCCESS        0 // Success code

#endif

// 00000001 int8_t char 256
// 00000010 int8_t char 256
// 00000111 int8_t char 256
// 11111111 11111111 11111111 11111111 int_32_t int 

// 1

// 3

// 7

// 5

// 4
// 7
// 1+2+4