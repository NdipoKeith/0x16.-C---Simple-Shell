#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	pid_t pid;
	pid_t ppid = getpid();
	size_t n = 5;
	char *lineptr;
	char *token;
	char *argvs[] = {" ", NULL};
	char *buf = "#cisfun$";
	printf("this is the parent pid %d\n", ppid);

	while (1)
	{
		write(STDOUT_FILENO, buf, 9);
		getline(&lineptr, &n, stdin);
		token = strtok(lineptr,  "\n");
		//free(lineptr);
		execve(token, argvs, NULL);
	}
	return (0);
}
