# 42_pipex

## Code Explanation: ##
  * pipex(int *fd, char **cmds, char *envp[]): This function is the main function to implement pipes in the shell. It creates two pipes to redirect the standard input and output between two commands.
  * ft_slave1(int fd, char *cmd1, int pip[2], char *envp[]): This function is executed by the first slave process and redirects the standard output to the first pipe and the standard input to the input file specified by the fd parameter.
  * ft_slave2(int fd, char *cmd2, int pip[2], char *envp[]): This function is executed by the second slave process and redirects the standard input to the second pipe and the standard output to the output file specified by the fd parameter.
  * get_path(char *cmd, char *envp[]): This function is used to get the full path of the command by searching the PATH environment variable.

## Functions Explanation: ##
  * pipe(int pip[2]): The pipe function creates a unidirectional communication channel between two processes. In this code, it is used to connect the standard output of the first slave process to the standard input of the second slave process.
  * fork(): The fork function creates a new process by duplicating the calling process. In this code, it is used to create two slave processes to run the commands specified by the cmds parameter.
  * dup2(int oldfd, int newfd): The dup2 function duplicates an existing file descriptor and makes it refer to a specified file descriptor. In this code, it is used to redirect the standard input and output between the slave processes and the input and output files.
