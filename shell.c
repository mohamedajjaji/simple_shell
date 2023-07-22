#include "s_shell.h"

/**
 * shell - Loop continues until a break condition is met
 *
 * Return: void
 */
void shell(void)
{
	char cmd[1024];

	while (1)
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "$ ", 2);

		if (fgets(cmd, sizeof(cmd), stdin) == NULL || cmd[0] == EOF)
			break;

		cmd[strcspn(cmd, "\n")] = '\0';
		if (strlen(cmd) == 0)
			continue;
		if (strcmp(cmd, "exit") == 0)
			break;

		exec_cmd(cmd);
	}
}
