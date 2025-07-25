#include "shell.h"
/**
 * _strcpy -  copy string
 * @dest: where to copy
 * @src: what to copy
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *start = dest;

	while ((*dest++ = *src++))
		;
	return (start);
}
/**
 * _strdup - duplicate string
 * @s: string to duplicate
 * Return: pointer
 */
char *_strdup(char *s)
{
	size_t len = _strlen(s) + 1;
	char *dup = malloc(len);

	if (dup == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	_strcpy(dup, s);
	return (dup);
}

/**
 * string_tok - Calls and implements _strtok function
 * @str: Command string
 * @delim: Delimiter string
 *
 * Return: Array of command-line arguments
 */
char **string_tok(char *str, char *delim)
{
	char **tokens = malloc(TOKEN_ARRAY_SIZE * sizeof(char *));
	char *token;
	int position = 0;

	if (!tokens)
	{
		perror("malloc");
		free_resources(tokens);
		return (NULL);
	}

	token = _strtok(str, delim);
	while (token != NULL)
	{
		if (token[0] == '"' && token[_strlen(token) - 1] == '"')
		{
			memmove(token, token + 1, _strlen(token) - 2);
			token[_strlen(token) - 2] = '\0';
		}

		tokens[position] = _strdup(token);
		if (!tokens[position])
		{
			perror("strdup");
			free_resources(tokens);
			return (NULL);
		}
		position++;
		token = _strtok(NULL, delim);
	}
	tokens[position] = NULL;

	return (tokens);
}

/**
* _strchr - Searches for the first occurrence ofcharacter 'c' in string 's'.
* @s: The string to be scanned.
* @c: The character to be searched in 's'.
* Return: pointer to first occurence of 'c' or NULL
*/
char *_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if ((char)c == '\0')
		return (s);
	return (NULL);
}
