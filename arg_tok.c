#include "shell.h"

/**
 * arg_tok - strtok the command
 * @arg: the command
 *
 * Return: 0 if error or the arg_cmd
*/

char **arg_tok(char *arg)
{
	char *arg_cpy = NULL, *token = NULL;
	char **arg_cmd = NULL;
	int size = 0, i = 0;

	if (!arg)
		return (NULL);

	arg_cpy = arg_dupl(arg);

	if (!arg_cpy)
		return (NULL);

	token = strtok(arg_cpy, " \t\n");

	while (token)
	{
		size++;
		token = strtok(NULL, " \t\n");
	}
	free(arg_cpy);
	arg_cmd = malloc(sizeof(char *) * (size + 1));
	if (!arg_cmd)
		return (NULL);
	token = strtok(arg, " \t\n");

	while (token)
	{
		arg_cmd[i] = arg_dupl(token);
		if (!arg_cmd[i])
		{
			free_arg(arg_cmd);
			return (NULL);
		}
		token = strtok(NULL, " \t\n");
		i++;
	}

	arg_cmd[i] = (NULL);

	return (arg_cmd);
}