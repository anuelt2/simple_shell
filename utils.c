#include "shell.h"

/**
* _path_size - get envp path size
* @envp: envppironment variable
* Return: size of path
*/
int _path_size(char **envp)
{
	int i = 0, j = 5;

	while (envp[i] != NULL)
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A' &&
			envp[i][2] == 'T' && envp[i][3] == 'H')
		{
			while (envp[i][j++] != '\0')
			;
		}
		i++;
	}

	return (j);
}

/**
* get_env_path - get the env path
* @envp: environment variable
* @size: size of environment path variable
* Return: pointer to path variable
*/
char *get_env_path(char **envp, int size)
{
	char *path;
	int i = 0, j = 5, k = 0;

	path = malloc(sizeof(char) * (size + 1));
	path[size] = '\0';
	while (envp[i] != NULL)
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A'
			&& envp[i][2] == 'T' && envp[i][3] == 'H')
		{
			while (envp[i][j++] != '\0')
				path[k++] = envp[i][j];
		}
		i++;
	}

	return (path);
}

/**
* _concatenate - Concatenate strings
* @dir: executable dir
* @pathname: command name
* Return: full path to command path
*/
char *_concatenate(char *dir, char *pathname)
{
	char *full_path;
	int i, j, k;

	full_path = malloc(sizeof(char) * 4096);
	full_path[4095] = '\0';
	if (!full_path)
		exit(EXIT_FAILURE);
	for (i = 0; i < 4096 && dir[i] != '\0'; i++)
	{
		full_path[i] = dir[i];
	}
	full_path[i] = '/';
	for (j = i + 1, k = 0; j < 4096 && pathname[k] != 0; j++, k++)
	{
		full_path[j] = pathname[k];
	}

	return (full_path);
}

/**
* is_executable - check if file is executable
* @full_path: path to check
* Return: 1 (success) or 0 (otherwise)
*/
int is_executable(char *full_path)
{
	struct stat sb;

	/* sb.st_mode - holds the exec and search permissions */
	/* S_IXUSR - Macro to  */
	return (stat(full_path, &sb) == 0 && sb.st_mode & S_IXUSR);
}

/**
* find_command - find the command in file path
* @pathname: the command to search for
* @envp: environment variable
* Return: path to command
*/
char *find_command(char *pathname, char **envp)
{
	char *env_path;
	char *dir;
	int path_size;
	char *full_path;

	path_size = _path_size(envp);
	full_path = malloc(sizeof(char) * 4096);
	full_path[4095] = '\0';
	env_path = malloc(sizeof(char) * (path_size + 1));
	env_path[path_size] = '\0';
	env_path = get_env_path(envp, path_size);
	if (!env_path)
		exit(EXIT_FAILURE);
	dir = strtok(env_path, ":");
	while (dir != NULL)
	{
		full_path = _concatenate(dir, pathname);
		if (is_executable(full_path) != 0)
		{
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(env_path);
	free(full_path);
	return ('\0');
}
