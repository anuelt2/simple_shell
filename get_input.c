#include "shell.h"

/**
 * get_input - Gets input from the commandline
 * @lineptr: Command string
 * @len: Size of string
 *
 * Return: Void
 */

void get_input(char *lineptr, size_t len)
{
	ssize_t char_read;

	lineptr = NULL;
	len = 0;
	char_read = getline(&lineptr, &len, stdin);
	if (char_read == -1)
	{
		printf("Error");
		return;
	}
	free(lineptr);
}
