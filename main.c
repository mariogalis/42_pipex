/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:02:22 by magonzal          #+#    #+#             */
/*   Updated: 2022/03/30 19:59:04 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*file1;
	char	*file2;
	char	*cmds[2];
	int		fd[2];

	if (!envp || !*envp)
		error("Error: Array of Pointers to Environment Variables");
	if (argc != 5)
		error("Error: Invalid Number of Arguments");
	file1 = argv[1];
	cmds[0] = argv[2];
	cmds[1] = argv[3];
	file2 = argv[4];
	fd[0] = open("f1", O_RDONLY);
	fd[1] = open("f2", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd[0] == -1 || fd[1] == -1)
		error("ERROR : CANNOT OPEN THE FILE");
	pipex(file1, cmds, file2, envp);
}
