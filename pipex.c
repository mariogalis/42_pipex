/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:19:32 by magonzal          #+#    #+#             */
/*   Updated: 2023/02/09 13:33:28 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int *fd, char **cmds, char *envp[])
{
	int		pip[2];
	pid_t	slave1;
	pid_t	slave2;
	int		status;
	int res = 0;

	pipe(pip);
	slave1 = fork();
	if (slave1 < 0)
		error("Error: Fork of salve 1",1);
	if (slave1 == 0)
		ft_slave1(fd[0], cmds[0], pip, envp);
	slave2 = fork();
	if (slave2 < 0)
		error("Error: Fork of slave 2",1);
	if (slave2 == 0)
		ft_slave2(fd[1], cmds[1], pip, envp);
	close(pip[0]);
	close(pip[1]);
	while (wait(&status) > 0)
			if (WIFEXITED(status))
				res = WEXITSTATUS(status);
	return (res);
}

void	ft_slave1(int fd, char *cmd1, int pip[2], char *envp[])
{
	char	**cmd;
	char	*path;

	dup2(pip[1], STDOUT_FILENO);
	close(pip[0]);
	dup2(fd, STDIN_FILENO);
	cmd = ft_split(cmd1, ' ');
	path = get_path(cmd[0], envp);
	if (fd == -1)
		error("Error: Can Not Read the Input File\n",1);
	if (execve(path, cmd, envp) == -1)
		error("ERROR: command not found\n",127);
}

void	ft_slave2(int fd, char *cmd2, int pip[2], char *envp[])
{
	char	**cmd;
	char	*path;

	dup2(pip[0], STDIN_FILENO);
	close(pip[1]);
	dup2(fd, STDOUT_FILENO);
	cmd = ft_split(cmd2, ' ');
	path = get_path(cmd[0], envp);
	printf("%s", path);
	if (fd == -1)
		error("Error: Can Not Read the Output File\n",1);
	if (execve(path, cmd, envp) == -1)
		error("ERROR: command not found\n",127);
}

char	*get_path(char *cmd, char *envp[])
{
	char	**paths;
	char	*goodpath;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
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
