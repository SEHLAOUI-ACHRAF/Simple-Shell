#include "shell.h"

/**
 * free_arg - function to free a 2D arry
 * @arg_cmd: the arg to be free
 *
 * Return: always 0
*/

void *free_arg(char **arg_cmd)
{
	int i = 0;

	if (arg_cmd == NULL)
		return (0);
	for (i = 0; arg_cmd[i] != NULL; i++)
	{
		free(arg_cmd[i]);
	}
	free(arg_cmd);
	return (0);
}