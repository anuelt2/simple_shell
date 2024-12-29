#include "shell.h"

/**
 * get_input - Gets glob.input from the commandline
 *
 * Return: Void
 */

void get_input(void)
{
	ssize_t char_read;
	size_t len;

	glob.input = NULL;
	len = sizeof(glob.input);
	char_read = getline(&glob.input, &len, stdin);
	if (char_read == -1)
	{
		if (feof(stdin))
		{
			_free((void **)&glob.input);
			/*	write(STDOUT_FILENO, "\n", 1);	*/
			exit(EXIT_SUCCESS);
		}
		else
		{
			_free((void **)&glob.input);
			perror("Getline Error");
			exit(EXIT_FAILURE);
		}
	}

	/*if (char_read > 0 && lineptr[char_read - 1] == '\n')*/
	/*{*/
	/*	lineptr[char_read - 1] = '\0';*/
	/*}*/
}
