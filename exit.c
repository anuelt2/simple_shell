#include "shell.h"

/**
 * exit_function - Executes exit built-in
 * @args: Array of command-line arguments
 *
 * Return: Void
 */

void exit_function(char *args[])
{
	if (args[1] != NULL)
		glob.status = atoi(args[1]);

	if (args != NULL)
		free_resources(args);
	if (glob.environ_copy)
		free_resources(glob.environ_copy);
	if (glob.input)
		_free((void **)&glob.input);

	exit(glob.status);
}

/**
 * handle_sigint - handle exit at Ctrl + C
 * @sig: Int representing the signal that was caught by the OS
 * Return: void
 */
void handle_sigint(int sig)
{
	free_resources(glob.environ_copy);
	_free((void **)&glob.input);
	exit(sig);
}
