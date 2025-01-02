#include "shell.h"

/**
 * _strtok - Custom strtok function
 * @str: String to be tokenized
 * @delim: Delimiter characters
 *
 * Return: Pointer to the next token or NULL if there are no more tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *last;
	unsigned int i = 0;
	char *token;

	if (str != NULL)
		last = str;

	if (last == NULL)
		return (NULL);

	while (last[i] != '\0' && strchr(delim, last[i]) != NULL)
		i++;

	if (last[i] == '\0')
		return (NULL);

	token = last + i;

	while (last[i] != '\0' && strchr(delim, last[i]) == NULL)
		i++;

	if (last[i] != '\0')
	{
		last[i] = '\0';
		last = last + i + 1;
	}
	else
		last = NULL;

	return (token);
}
