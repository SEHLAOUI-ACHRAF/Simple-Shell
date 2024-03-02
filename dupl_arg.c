#include "shell.h"
/**
 * arg_dupl - function that duplicate a given string
 * @arg: string to duplicate
 *
 * Return: the duplication
*/

char *arg_dupl(const char *arg)
{
	char *duplicated_arg;
	int i, arg_len = 0;

	if (arg == NULL)
		return (NULL);

	while (arg[arg_len] != '\0')
	{
		arg_len++;
	}
	duplicated_arg = malloc(sizeof(char) * (arg_len + 1));

	if (duplicated_arg == NULL)
		return (NULL);
	for (i = 0; i < arg_len; i++)
		duplicated_arg[i] = arg[i];

	duplicated_arg[arg_len] = '\0';

	return (duplicated_arg);
}