/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:10:00 by magonzal          #+#    #+#             */
/*   Updated: 2022/03/22 12:16:52 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>

void	pipex(char *file1, char *cmd1, char *cmd2, char *file2);
void	ft_slave1(char *file1, char *cmd1);
void	ft_slave2(char *file2, char *cmd2);
void	get_path(char *cmd, char *envp[]);
void	error(char *err);
#endif
