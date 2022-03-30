#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	char *cmd = "cat";
	char **path;
	path = get_path(cmd, envp);

	for(int i=0; path[i]!=NULL; i++)
		printf("%s",path[i]);

}

char	**get_path(char *cmd, char *envp[])
{
	char	**path;
	int		i;
	int		j;

	while (envp[i] && ft_strncmp(envp[i],"PATH=",5))
		i++;
	path = ft_split(envp[i] + 5,':');
	return(path);
}

/////////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>

// int	main(int argc, char **argv, char **envp)
// {
// 	for (char **env = envp; *env != 0; env++)
// 	{
// 	char *thisEnv = *env;
// 	printf("%s\n", thisEnv);
// 	}
// 	return 0;
// }