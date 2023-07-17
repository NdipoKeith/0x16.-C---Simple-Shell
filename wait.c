#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Unsuccessful");
		return (1);
	}
	if (pid == 0)
	{
		printf("child process\n");
	}
	else
	{
		wait(NULL);
		sleep(30);
		printf("parent process\n");
	}
	return (0);
}
