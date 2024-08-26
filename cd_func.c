#include "shell.h"

/**
* home_path_size - Get home path size
* @envp: Environment variable
*
* Return: Size of path
*/

int home_path_size(char **envp)
{
	int i = 0, j = 4;

	while (envp[i] != NULL)
	{
		if (envp[i][0] == 'H' && envp[i][1] == 'O' &&
			envp[i][2] == 'M' && envp[i][3] == 'E')
		{
			while (envp[i][j++] != '\0')
			;
		}
		i++;
	}

	return (j);
}

/**
* get_home_path - Get the home path
* @envp: Environment variable
* @size: Size of environment path variable
*
* Return: Pointer to path variable
*/

char *get_home_path(char **envp, int size)
{
	char *path;
	int i = 0, j = 4, k = 0;

	size = home_path_size(envp);
	path = malloc(sizeof(char) * (size + 1));
	path[size] = '\0';
	while (envp[i] != NULL)
	{
		if (envp[i][0] == 'H' && envp[i][1] == 'O'
			&& envp[i][2] == 'M' && envp[i][3] == 'E')
		{
			while (envp[i][j++] != '\0')
				path[k++] = envp[i][j];
		}
		i++;
	}

	return (path);
}

/**
 * change_directory - Changes directory
 * @path: Directory path
 *
 * Return - Void
 */

void change_directory(const char *path)
{
	if (chdir(path) == 0)
		;
	else
	{
		perror("cd");
	}
}

/**
 * cd_args - Handles cd built-in command arguments
 * @args: Pointer to cd command arguments
 * @envp: Pointer to environment variables
 *
 * Return: 1 (success)
 */

int cd_args(char **args, char **envp)
{
	const char *path;
	char buf[1024];
	int size;

	(void)envp;
	if (strcmp(args[1], "-") == 0)
	{
		getcwd(buf, sizeof(buf));
		setenv("OLDPWD", buf, 1);
		size = oldpwd_path_size(envp);
		path = get_oldpwd_path(envp, size);
		chdir(path);
		getcwd(buf, sizeof(buf));
		setenv("PWD", buf, 1);
		return (1);
	}
	else
	{
		getcwd(buf, sizeof(buf));
		setenv("OLDPWD", buf, 1);
		path = args[1];
		chdir(path);
		getcwd(buf, sizeof(buf));
		setenv("PWD", buf, 1);
		return (1);
	}

	return (0);
}
