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
 * _strcat - concat string
 * @dest: where to add to
 * @src: what to add
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	char *start = dest;

	while (*dest)
		dest++;
	while ((*dest++ = *src++))
		;
	return (start);
}
/**
 * string_tok - Calls and implements strtok function
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

	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[position] = _strdup(token);
		if (!tokens[position])
		{
			perror("strdup");
			free_resources(tokens);
			return (NULL);
		}
		position++;
		token = strtok(NULL, delim);
	}
	tokens[position] = NULL;

	return (tokens);
}

/**
 * format_env_var - link a path var to its value
 * @name: variable name
 * @value: variable value
 * Return: pointer to the combined string
 */
char *format_env_var(char *name, char *value)
{
	size_t len = _strlen(name) + _strlen(value) + 2;
	char *env_var = malloc(len);

	if (!env_var)
		return (NULL);

	_strcpy(env_var, name);
	_strcat(env_var, "=");
	_strcat(env_var, value);

	return (env_var);
}
