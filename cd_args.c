#include "shell.h"

/**
 * cd_args - Handles cd built-in command arguments
 * @args: Pointer to the cd command arguments
 * @envp: Pointer to environment variables
 * @shell: name of the running shell
 * @cmd_count: Count of commands entered in each shell session
 *
 * Return: 1 (success)
 */

int cd_args(char **args, char **envp, char *shell, int cmd_count)
{
	char *path = NULL;
	char buf[1024];

	(void)envp;
	if (_strcmp(args[1], "-") == 0)
	{
		path = get_oldpwd_path(envp, oldpwd_path_size(envp));
		getcwd(buf, sizeof(buf));
		setenv("OLDPWD", buf, 1);
		fprintf(stdout, "%s\n", path);
		chdir(path);
		getcwd(buf, sizeof(buf));
		setenv("PWD", buf, 1);
		free(path);
		return (1);
	}
	else
	{
		getcwd(buf, sizeof(buf));
		setenv("OLDPWD", buf, 1);
		if (access(args[1], F_OK) == 0)
		{
			path = args[1];
		}
		else
		{
			fprintf(stderr, "%s: %d: %s: can't cd to %s\n",
			shell, cmd_count, args[0], args[1]);
		}
		path = args[1];
		chdir(path);
		getcwd(buf, sizeof(buf));
		setenv("PWD", buf, 1);
		return (1);
	}

	return (0);
}
