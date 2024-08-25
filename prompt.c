#include "shell.h"

/**
 * display_prompt - Displays commandline prompt
 *
 * Return: Void
 */

void display_prompt(void)
{
	write(STDOUT_FILENO, "#simple_shell$ ", 15);
	fflush(stdout);
}
