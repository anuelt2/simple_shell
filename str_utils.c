#include "shell.h"

/**
 * _strlen - calculates lenght of a string
 * @str: string to measure
 * Return: len of string
 */
size_t _strlen(char *str)
{
	size_t i;

	if (!str)
		exit(EXIT_FAILURE);

	for (i = 0; str[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: int - 0 (Same), otherwise (The opposite)
 */
int _strcmp(char *str1, char *str2)
{
	int i, x = 1;

	for (i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
		{
			x = str1[i] - str2[i];
			break;
		}
		else
		{
			x = str1[i] - str2[i];
		}
	}

	return (x);
}

/**
 * _strncmp - compares two strings up until nth index
 * @str1: first string
 * @str2: second string
 * @n: nth index to check up to.
 * Return: int - 0 (Same), otherwise (The opposite)
 */
size_t _strncmp(char *str1, char *str2, size_t n)
{
	size_t i, x = 1;

	for (i = 0; i < n && (str1[i] != '\0' || str2[i] != '\0'); i++)
	{
		if (str1[i] != str2[i])
		{
			x = str1[i] - str2[i];
			break;
		}
		else
		{
			x = str1[i] - str2[i];
		}
	}

	return (x);
}

/**
 * _concat - full a variable to its value
 * @var: variable name
 * @val: its value
 * Return: A pointer to the combined output
 */
char *_concat(char *var, char *val)
{
	char *full_var;
	size_t j, var_len = _strlen(var), val_len = _strlen(val);
	size_t i, k, full_var_len = var_len + val_len + 2;

	full_var = malloc(sizeof(char) * full_var_len);
	full_var[full_var_len - 1] = '\0';
	if (!full_var)
		exit(EXIT_FAILURE);
	for (i = 0; i < full_var_len && var[i] != '\0'; i++)
	{
		full_var[i] = var[i];
	}
	full_var[i] = '=';
	for (j = i + 1, k = 0; j < full_var_len && val[k] != 0; j++, k++)
	{
		full_var[j] = val[k];
	}

	return (full_var);
}

/**
 * _strcon - check if a string contains a char
 * @str: string to chekc
 * @c: char to check for
 * Return: 0 (contains), otherwise (Doesn't contain)
 */
int _strcon(char *str, char c)
{
	int i = 0, x = 1;

	while (str[i++] != '\0')
	{
		if (str[i] == c)
		{
			return (0);
		}
		else
		{
			x = str[i] - c;
		}
	}

	return (x);
}
