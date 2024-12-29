#include "shell.h"

/**
 * env_size - get environ size
 * Return: length of environ
 */
int env_size(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		;

	return (i);
}

/**
 * get_env_size - get environ size
 * @env: environment variable size to measure
 * Return: length of env list size
 */
int get_env_size(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
		;

	return (i);
}

/**
 * get_env_var_value_len - get an env var's value
 * @env: environment list
 * @var: variable name
 * Return: pointer to this value
 */
int get_env_var_value_len(char **env, char *var)
{
	int n = 0;
	size_t i, j, var_len = _strlen(var);

	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(env[i], var, var_len) == 0 && env[i][var_len] == '=')
		{
			for (j = var_len; env[i][j] != '\0'; j++)
				n++;
		}
	}
	return (n);
}

/**
 * get_env_var_value - get an env var's value
 * @env: environment list
 * @var: variable name
 * Return: pointer to this value
 */
char *get_env_var_value(char **env, char *var)
{
	int i;
	size_t var_len = _strlen(var);

	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(env[i], var, var_len) == 0 && env[i][var_len] == '=')
		{
			return (_strdup(env[i] + var_len + 1));
		}
	}
	return (NULL);
}
/**
 * copy_environ - create a copy of environ
 * Return: pointer to copy of environ
 */
char **copy_environ(void)
{
	int i, j, env_var_len, environ_size = env_size();

	glob.environ_copy = malloc(sizeof(char *) * (environ_size + 1));
	if (!glob.environ_copy)
		exit(EXIT_FAILURE);
	glob.environ_copy[environ_size] = NULL;
	for (i = 0; environ[i] != NULL; i++)
	{
		env_var_len = _strlen(environ[i]);
		glob.environ_copy[i] = malloc(sizeof(char) * (env_var_len + 1));
		if (!glob.environ_copy[i])
			exit(EXIT_FAILURE);
		for (j = 0; environ[i][j] != '\0'; j++)
			glob.environ_copy[i][j] = environ[i][j];
		glob.environ_copy[i][env_var_len] = '\0';
	}
	return (glob.environ_copy);
}
