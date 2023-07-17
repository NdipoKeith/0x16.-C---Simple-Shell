#include "shell.h"

/**
 * shell_cd - changes the current working directory
 * @args: Argument of the currrent working directory
 * Return: Current working directory
 */
void shell_cd(char **args)
{
	char *dir = args[1];
	int ret;

	if (dir == NULL)
	{
		dir = getenv("HOME");
		puts("cd: No HOME directory found\n");
		return;
	}
	ret = chdir(dir);
	if (ret < 0)
	{
		perror("cd");
	}
}
