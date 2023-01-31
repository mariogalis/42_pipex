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

void	pipex(int *fd, char **cmds, char *envp[])
{
	int		pip[2];
	pid_t	slave1;
	pid_t	slave2;

	pipe(pip);
	slave1 = fork();
	if (slave1 < 0)
		error("Error: Fork of salve 1");
	if (slave1 == 0)
		ft_slave1(fd[0], cmds[0], pip, envp);
	slave2 = fork();
	if (slave2 < 0)
		error("Error: Fork of slave 2");
	if (slave2 == 0)
		ft_slave2(fd[1], cmds[1], pip, envp);
	close(pip[0]);
	close(pip[1]);
	waitpid(slave1, NULL, 0);
	waitpid(slave2, NULL, 0);
}

void	ft_slave1(int fd, char *cmd1, int pip[2], char *envp[])
{
	char	**cmd;
	char	*path;

	dup2(pip[1], 1);
	close(pip[0]);
	dup2(fd, 0);
	cmd = ft_split(cmd1, ' ');
	path = get_path(cmd[0], envp);
	if (fd == -1)
		error("Error: Can Not Read the Input File\n");
	if (execve(path, cmd, envp) == -1)
		error("ERROR: BAD EXECVE 1\n");
}

void	ft_slave2(int fd, char *cmd2,int pip[2], char *envp[])
{
	char	**cmd;
	char	*path;

	dup2(pip[0], 0);
	close(pip[1]);
	dup2(fd, 1);
	cmd = ft_split(cmd2, ' ');
	path = get_path(cmd[0], envp);
	printf("%s", path);
	if (fd == -1)
		error("Error: Can Not Read the Output File\n");
	if (execve(path, cmd, envp) == -1)
		error("ERROR: BAD EXECVE 2\n");
}

char	*get_path(char *cmd, char *envp[])
{
	char	**paths;
	char	*goodpath;
	int		i = 0;
	int		j = 0;

	while (envp[i] && ft_strncmp(envp[i],"PATH=",5))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	cmd = ft_strjoin("/", cmd);
	while (paths[j])
	{
		goodpath = ft_strjoin(paths[j], cmd);
		if (access(goodpath, 0) == 0)
			return (goodpath);
		j++;
	}
	exit(0);
}
