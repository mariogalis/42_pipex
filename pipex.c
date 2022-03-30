/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:19:32 by magonzal          #+#    #+#             */
/*   Updated: 2022/03/30 20:40:54 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char *file1, char **cmds, char *file2, char *envp[])
{
	int		pip[2];
	int		fd[2];
	int		status;
	pid_t	slave1;
	pid_t	slave2;

	pipe(pip);
	slave1 = fork();
	if (slave1 < 0)
		error("Error: Fork of salve 1");
	if (slave1 == 0)
		ft_slave1(file1, cmds[0], pip, envp);
	slave2 = fork();
	if (slave2 < 0)
		error("Error: Fork of slave 2");
	if (slave2 == 0)
		ft_slave2(file2, cmds[1], pip, envp);
	close(pip[0]);
	close(pip[1]);
	waitpid(slave1, &status, 0);
	waitpid(slave2, &status, 0);
}

void	ft_slave1(char *file1, char *cmd1, int pip[2], char *envp[])
{
	int	fd;

	fd = open("f1", O_RDONLY);
	if (fd == -1)
		error("Error: Can Not Read the Input File");
	dup2(fd, STDIN_FILENO);
	dup2(pip[1], STDOUT_FILENO);
	execve(get_path(cmd1, envp), &cmd1, envp);
	close(fd);
}

void	ft_slave2(char *file2, char *cmd2, int pip[2], char *envp[])
{
	int	fd;

	fd = open("f2", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		error("Error: Can Not Read the Output File");
	dup2(fd, STDOUT_FILENO);
	if( execve(get_path(cmd2, envp), &cmd2, envp) == -1)
		error("ERROR: BAD EXECVE");
	close(fd);
}

char	*get_path(char *cmd, char *envp[])
{
	char	**paths;
	char	*good_path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	cmd = ft_strjoin("/", cmd);
	good_path = ft_strjoin(*paths, cmd);
	while (paths++)
	{
		if (access(ft_strjoin(paths[j], good_path), F_OK) == 0)
			good_path = paths[j];
		j++;
	}
	return (good_path);
}
