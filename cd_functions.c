#include "shell.h"

/**
 * set_oldpwd - Sets the OLDPWD environment variable
 *
 * Return: 0 (success)
 */

int set_oldpwd(void)
{
	char buf[PATH_MAX];

	if (getcwd(buf, sizeof(buf)) != NULL)
	{
		setenv("OLDPWD", buf, 1);
	}
	else
	{
		perror("getcwd error");
		return (-1);
	}

	return (0);
}

/**
 * set_pwd - Sets the PWD environment variable
 *
 * Return: 0 (success)
 */

int set_pwd(void)
{
	char buf[PATH_MAX];

	if (getcwd(buf, sizeof(buf)) != NULL)
	{
		setenv("PWD", buf, 1);
	}
	else
	{
		perror("getcwd error");
		return (-1);
	}

	return (0);
}

/**
 * cd_exec - Executes cd commands
 * @args: Array of commandline arguments
 * @envp: Pointer to environment variables
 * @shell: name of the running shell
 * @cmd_count: Count of commands entered in each shell session
 *
 * Return: 0 (success)
 */

int cd_exec(char *args[], char **envp, char *shell, int cmd_count)
{
	char *path = NULL;
	int size;

	if (args[1] == NULL)
	{
		set_oldpwd();
		size = home_path_size(envp);
		path = get_home_path(envp, size);
		if (path == NULL)
		{
			fprintf(stderr, "cd: no home directory\n");
			free_resources(args);
			free(path);
			return (-1);
		}
		if (chdir(path) != 0)
		{
			perror("cd");
			free_resources(args);
			free(path);
			return (-1);
		}
		set_pwd();
		free_resources(args);
		free(path);
		return (1);
	}
	if (args[1] != NULL)
	{
		cd_args(args, envp, shell, cmd_count);
		free_resources(args);
		free(path);
		return (1);
	}
	free_resources(args);
	free(path);
	return (0);
}
