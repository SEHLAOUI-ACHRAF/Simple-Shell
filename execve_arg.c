#include "shell.h"

/**
 * execve_arg - function to execut the command (arg_cmd)
 * @arg_cmd: the command to be execut
 * @av: is a NULL terminated array of strings
 *
 * Return: 127 if the command is NULL or the id (STATUS) of the error
*/

int execve_arg(char **arg_cmd, char **av)
{
	pid_t i;
	int id;
	int s;

	i = fork();
	if (i == 0)
	{
		s = execve(arg_cmd[0], arg_cmd, environ);
		if (s == -1)
		{
			perror(av[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (i < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(i, &id, 0);
		if (WEXITSTATUS(id))
		{
			return (WEXITSTATUS(id));
		}
	}
	return (-1);
}