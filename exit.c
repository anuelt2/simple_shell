#include "shell.h"

/**
 * exit_function - Executes exit built-in
 * @args: Array of commandline arguments
 *
 * Return: Void
 */

void exit_function(char *args[])
{
	int status;

	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			status = atoi(args[1]);
			exit(status);
		}
		else
		{
			exit(0);
		}
	}
}
