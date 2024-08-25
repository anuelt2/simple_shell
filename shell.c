#include "shell.h"

/**
 * main - Shell program entry point
 * @argc: Number of commandline arguments
 * @argv: Pointer to array of commandline arguments
 * @envp: Pointer to array of environment variables
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[], char *envp[])
{
	char input[128];
	char *delim = DELIM;
	char *str;
	char *pathname;
	char **args;
	int count;

	(void)argc;
	(void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			display_prompt();
		}
		str = get_input(input, sizeof(input));
		args = string_tok(str, delim);
		pathname = args[0];
		if (args[0] == NULL)
		{
			free(str);
			free(args);
			continue;
		}
		execute_builtin(args);
		execute_external(pathname, args, envp);
		free(args);
		free(str);
	}
	printf("%d", count);

	return (0);
}
