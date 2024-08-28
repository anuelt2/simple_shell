#include "shell.h"

/**
 * get_input - Gets input from the commandline
 * @lineptr: The pointer to the command string
 * @len: Size of string
 *
 * Return: Void
 */

char *get_input(char *lineptr, size_t len)
{
	ssize_t char_read;

	lineptr = NULL;
	len = 0;
	char_read = getline(&lineptr, &len, stdin);
	if (char_read == -1)
	{
		if (feof(stdin))
		{
			free(lineptr);
			/*write(STDOUT_FILENO, "\n", 1);*/
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(lineptr);
			perror("Getline Error");
			exit(EXIT_FAILURE);
		}
	}
	/*lineptr[strcspn(lineptr, "\n")] = '\0';*/

	return (lineptr);
}
