#include "shell.h"

/**
 * main - Shell program entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char input[128];
	char *delim = " ";
	char *str;

	while (1)
	{
		display_prompt();
		str = get_input(input, sizeof(input));
		string_tok(str, delim);
	}
	free(input);

	return (0);
}
