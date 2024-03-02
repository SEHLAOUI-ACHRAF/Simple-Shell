#include "shell.h"
/**
 * main - the main function to get the simple_shell work
 * @ac: is the number of items in av
 * @av: is a NULL terminated array of strings
 * Return: always 0;
*/

int main(int ac, char **av)
{
	char *arg = NULL, **arg_cmd = NULL;
	size_t len = 0;
	int i;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		i = getline(&arg, &len, stdin);
		if (i == -1)
		{
			free(arg);
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			exit(0);
		}
		arg_cmd = arg_tok(arg);
		if (arg_cmd == NULL || arg_cmd[0] == NULL)
		{
			free(arg_cmd);
			continue;
		}
		if (comp_arg(arg_cmd[0], "exit") == 1)
		{
			free_arg(arg_cmd);
			free(arg);
			exit(0);
		}
		execve_arg(arg_cmd, av);
		free_arg(arg_cmd);
	}
	free(arg);
	return (0);
}