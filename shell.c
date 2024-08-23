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
	char *full_path;
	char **args;
	(void)argc;
	(void)argv;

	full_path = malloc(sizeof(char) * 4096);
	full_path[4095] = '\0';
	if (!full_path)
		exit(EXIT_FAILURE);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			display_prompt();
		}
		str = get_input(input, sizeof(input));
		args = string_tok(str, delim);
		full_path = find_command(args[0], envp);
		if (is_executable(args[0]) != 0)
		{
			execute(args[0], args, envp);
			free(args);
			free(str);
		}
		else
		{
			execute(full_path, args, envp);
			free(full_path);
			free(args);
			free(str);
		}
	}

	return (0);
}
