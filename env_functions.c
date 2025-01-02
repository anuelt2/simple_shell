#include "shell.h"

/**
 * get_env - print env variables
 * Return: void
 */
void get_env(void)
{
	int i, j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			write(STDOUT_FILENO, &environ[i][j], 1);
		}
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * set_env - Initialise new env var or modify an existing one
 * @var: variable name to create or modify
 * @val: value to give to pass to var
 * @overwrite: instruction to overwrite existing variable
 * Return: int
 */
int set_env(char *var, char *val, int overwrite)
{
	int i, var_len, environ_copy_size;
	char *new_var = _concat(var, val);

	if (!glob.environ_copy)
		copy_environ();
	environ_copy_size = get_env_size(glob.environ_copy);

	if (!var && _strcon(var, '=') != 0)
		return (-1);

	var_len = _strlen(var);
	for (i = 0; glob.environ_copy[i] != NULL; i++)
	{
		if (_strncmp(glob.environ_copy[i], var, var_len) == 0 &&
			glob.environ_copy[i][var_len] == '=')
		{
			if (overwrite == 0)
				return (0);
			break;
		}
	}

	if (glob.environ_copy[i] != NULL)
	{
		glob.environ_copy[i] = new_var;
	}
	else
	{
		glob.environ_copy = realloc(glob.environ_copy, sizeof(char *) *
		(environ_copy_size + 2));
		if (!glob.environ_copy)
			return (-1);
		glob.environ_copy[environ_copy_size] = new_var;
		glob.environ_copy[environ_copy_size + 1] = NULL;
		environ_copy_size++;
	}
	environ = glob.environ_copy;
	return (0);
}

/**
 * unset_env - unset an environment variable
 * @var: variable to delete
 * Return: 0 (success), -1 (failure)
 */
int unset_env(char *var)
{
	char *temp;
	int i, var_len, environ_copy_size = get_env_size(glob.environ_copy);

	if (!var && _strcon(var, '=') != 0)
		return (-1);
	var_len = _strlen(var);
	for (i = 0; glob.environ_copy[i] != NULL; i++)
	{
		if (_strncmp(glob.environ_copy[i], var, var_len) == 0 &&
			glob.environ_copy[i][var_len] == '=')
		{
			break;
		}
	}

	while (i <= environ_copy_size)
	{
		temp = glob.environ_copy[i + 1];
		if (_strncmp(glob.environ_copy[i], var, var_len) == 0 &&
			glob.environ_copy[i][var_len] == '=')
			_free((void **)&glob.environ_copy[i]);
		glob.environ_copy[i] = temp;
		environ_copy_size--;
		i++;
	}
	environ = glob.environ_copy;

	return (0);
}

/**
 * env_function_caller - calls env, setenv, and unsetenv
 * @args: prompt tokens
 * Return: 0 (Falsy) - 1 (Truthy)
 */
int env_function_caller(char **args)
{
	if (_strcmp(args[0], "env") == 0)
	{
		get_env();
		return (1);
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		if (args[1] && args[2])
			set_env(args[1], args[2], 1);
		return (1);
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1])
			unset_env(args[1]);
		return (1);
	}
	return (0);
}
