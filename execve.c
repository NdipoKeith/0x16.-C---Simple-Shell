#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;
	pid_t ppid = getpid();
	int i = 0;
	char *argv[] = {"/bin/ls",  "-l",  NULL};
	printf("This is the parent pid %d\n", ppid);
	
	while (1)
	{
		if (i == 5)
			break;
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0)
		{
			int val = execve(argv[0], argv, NULL);
			if (val == -1)
				perror("Error");
		}
		else
		{
			wait(NULL);
			printf("Done on with execve\n");
		}i++;
	}
	return (0);
}
