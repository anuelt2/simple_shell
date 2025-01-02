#include "shell.h"

/**
 * exec_builtin - Executes built-in commands
 * @args: Array of command-line arguments
 * @envp: Pointer to environment variables
 * @shell: name of the running shell
 * @cmd_count: Count of commands entered in each shell session
 *
 * Return: Void
 */

int exec_builtin(char *args[], char **envp, char *shell, int cmd_count)
{
	if (args[0] != NULL)
	{
		if (strcmp(args[0], "exit") == 0)
			exit_function(args);
		if (strcmp(args[0], "cd") == 0)
		{
			cd_exec(args, envp, shell, cmd_count);
			_free((void **)&glob.input);
			return (1);
		}
	}
	return (0);
}

/**
 * exec_external - Executes external commands
 * @comm: Program to execute
 * @args: Array of commandline arguments
 * @shell: name of shell
 * @envp: Pointer to array of environment variables
 * @cmd_count: Count of commands entered in each shell session
 *
 * Return: Void
 */

void exec_external(char *comm, char *args[], char *shell, char *envp[],
int cmd_count)
{
	pid_t child_pid;

	find_ext_file(comm, envp);
	if (glob.comm_path)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Fork Error");
			_free((void **)&glob.comm_path);
		}
		if (child_pid == 0)
		{
			if ((execve(glob.comm_path, args, envp) == -1))
			{
				perror("execve failed");
				_free((void **)&glob.comm_path);
				exit(EXIT_FAILURE);
			}
		}
		wait(&glob.status);
		_free((void **)&glob.comm_path);

	}
	else
	{
		fprintf(stderr, "%s: %d: %s: not found\n", shell, cmd_count, comm);
		_free((void **)&glob.comm_path);
		if (args != NULL)
		free_resources(args);
		if (glob.environ_copy)
			free_resources(glob.environ_copy);
		if (glob.input)
			_free((void **)&glob.input);
		exit(127);
	}
}
