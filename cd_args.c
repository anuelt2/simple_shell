#include "shell.h"

/**
 * exec_builtin - Executes built-in commands
 * @args: Array of commandline arguments
 * @envp: Pointer to environment variables
 *
 * Return: Void
 */

int exec_builtin(char *args[], char **envp)
{
	const char *path;
	int size;
	char buf[1024];

	if (args[0] != NULL)
	{
		exit_function(args);
	}
	if (args[0] != NULL && (strcmp(args[0], "cd") == 0))
	{
		if (args[1] == NULL)
		{
			if (getcwd(buf, sizeof(buf)) != NULL)
			{
				setenv("OLDPWD", buf, 1);
			}
			else
			{
				perror("getcwd error");
				return (-1);
			}
			size = home_path_size(envp);
			path = get_home_path(envp, size);
			if (path == NULL)
			{
				fprintf(stderr, "cd: no home directory\n");
				return (-1);
			}
			if (chdir(path) != 0)
			{
				perror("cd");
				return (-1);
			}
			if (getcwd(buf, sizeof(buf)) != NULL)
			{
				setenv("PWD", buf, 1);
			}
			else
			{
				perror("getcwd error");
				return (-1);
			}
			return (1);
		}
		if (args[1] != NULL)
		{
			cd_args(args, envp);
			return (1);
		}
	}
	return (0);
}

/**
 * exec_external - Executes external commands
 * @pathname: Program to execute
 * @args: Array of commandline arguments
 * @envp: Pointer to array of environment variables
 * @cmd_count: Count of commands entered in each shell session
 *
 * Return: Void
 */

void exec_external(char *pathname, char *args[], char *envp[], int cmd_count)
{
	pid_t child_pid;
	int status;
	char *full_path;

	full_path = find_ext_file(pathname, envp, cmd_count);
	if (is_executable(full_path))
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Fork Error");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			if ((execve(full_path, args, envp)) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}
}
