#include "shell.h"

/**
 * string_tok - Calls and implements strtok function
 * @str: Command string
 * @delim: Delimiter string
 */

void string_tok(char *str, char *delim)
{
	char *token;
	char *args[128];
	int token_count;
	int array_size;

	delim = " \t\n";
	token_count = 0;
	array_size = TOKEN_ARRAY_SIZE;

	*args = malloc(sizeof(char *) * array_size);
	if (*args == NULL)
	{
		printf("Error");
		exit(1);
	}

	token = strtok(str, delim);
	while (token != NULL)
	{
		if (token_count >= array_size)
		{
			array_size *= 2;
			*args = realloc(*args, sizeof(char *) * array_size);
			if (*args == NULL)
			{
				printf("Error");
				exit(1);
			}
		}
		args[token_count] = token;
		token_count++;
		token = strtok(NULL, delim);
	}
	args[token_count] = '\0';
}
