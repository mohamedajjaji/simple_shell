#include "s_shell.h"

/**
 * error_handling - Prints a handled error message
 * @message: Pointer to the message to be printed
 *
 * Return: void
 */
void error_handling(const char *message)
{
	perror(message);
}

/**
 * exec_cmd - Executes a command
 * @cmd: Pointer to the command to be executed
 *
 * Return: void
 */
void exec_cmd(const char *cmd)
{
	int status;
	const char **args = malloc(2 * sizeof(char *));
	char cmd_cpy[1024];
	pid_t pid;

	strncpy(cmd_cpy, cmd, 1024);
	args[0] = strtok(cmd_cpy, " \t\n");
	pid = fork();
	if (pid == 0)
	{
		execvp(args[0], (char *const *)args);
		error_handling("Execution failed");
		free(args);
		_exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		free(args);
	}
	else
	{
		error_handling("Fork failed");
		free(args);
		exit(EXIT_FAILURE);
	}
}
