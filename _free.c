#include "shell.h"

/**
 * _free - custom free function for double pointers
 * @ptr: pointer to the double pointer to clear
 * Return: void
 */
void _free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/**
 * free_resources - function to use _free to free double pointers
 * @args: double pointer to free
 * Return: void
 */
void free_resources(char **args)
{
	size_t i = 0;

	if (!args)
		return;

	for (i = 0; args[i]; i++)
		_free((void **)&args[i]);
	_free((void **)&args);
}
