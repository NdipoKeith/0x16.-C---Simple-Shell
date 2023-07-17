#include "shell.h"

/**
 * execute - should execute a command with arguments
 * @argv: an array of strings containing the command and its arguments
 *
 * Return: the exit status of the executed command
 */
int execute(char **argv)
{
	pid_t id;
	int status = 0;
	char *cd_path, *envp[2];

	if (argv == NULL || *argv == NULL)
		return (status);
	if (check_for_builtin(argv))
		return (status);

	id = fork();
	if (id == -1)
	{
		_puterror("fork");
		return (1);
	}
	if (id == -1)
		perror(argv[0]), free_tokens(argv), free_last_input();
	if (id == 0)
	{
		envp[0] = get_path();
		envp[1] = NULL;
		cd_path = NULL;
		if (argv[0][0] != '/')
			cd_path = find_in_path(argv[0]);
		if (cd_path == NULL)
			cd_path = argv[0];
		if (execve(cd_path, argv, envp) == -1)
		{
			perror(argv[0]), free_tokens(argv), free_last_input();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(id, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (status);
}
