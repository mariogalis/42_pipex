/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:10:00 by magonzal          #+#    #+#             */
/*   Updated: 2022/03/30 20:37:09 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>

void	pipex(int *fd, char **cmds,char *envp[]);
void	ft_slave1(int fd, char *cmd1, int pip[2], char *envp[]);
void	ft_slave2(int fd, char *cmd2, int pip[2], char *envp[]);
char	*get_path(char *cmd, char *envp[]);
void	error(char *err);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
#endif
