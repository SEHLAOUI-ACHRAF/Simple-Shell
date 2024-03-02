#include "shell.h"

/**
 * comp_arg - function to compare tow args
 * @arg1: the first arg
 * @arg2: the second arg
 *
 * Return: 0 if not equal else 1 if equal
*/

int comp_arg(char *arg1, char *arg2)
{
	while (*arg1 != '\0' && *arg2 != '\0')
	{
	if (*arg1 != *arg2)
	{
		return (0);
	}
		arg1++;
		arg2++;
	}

	return (*arg1 == '\0' && *arg2 == '\0');
}