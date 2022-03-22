/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:19:32 by magonzal          #+#    #+#             */
/*   Updated: 2022/03/22 12:18:48 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char *file1, char *cmd1, char *cmd2, char *file2)
{
	int		pip[2];
	int		status;
	pid_t	slave1;
	pid_t	slave2;

	pipe(pip);
	slave1 = fork();
	if (slave1 < 0)
		error("Error: Fork of salve 1");
	if (slave1 == 0)
		ft_slave1(file1, cmd1);
	slave2 = fork();
	if (slave2 < 0)
		error("Error: Fork of slave 2");
	if (slave2 == 0)
		ft_slave2(file2, cmd2);
	close(pip[0]);
	close(pip[1]);
	waitpid(slave1, &status, 0);
	waitpid(slave2, &status, 0);
}

void	ft_slave1(char *file1, char *cmd1)
{
	int	fd;

	fd = open("f1", O_RDONLY);
	if (fd == -1)
		error("Error: Can Not Read the Input File");
	//get_path();
	//exceve();
}

void	ft_slave2(char *file2, char *cmd2)
{
	int	fd;

	fd = open("f2", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		error("Error: Can Not Read the Output File");
	//get_path();
	//exceve();
}

void	get_path(char *cmd, char *envp[])
{
	
}