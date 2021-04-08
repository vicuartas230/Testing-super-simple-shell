#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv)
{
	int wait_pid, i = 0;
	int pid;

	while (i < 5)
	{
		pid = fork();
		wait_pid = wait(NULL);
		if (pid == 0)
		{
			if (execve(argv[1], argv, NULL) < 0)
				printf("failed to exec");
		}
		else if (pid == -1)
		{
			printf ("ERROR \n");
			exit(1);
		}
		else
		{
			printf ("%d %d %d \n", getpid(), pid, wait_pid);
			wait_pid = wait(NULL);
		}
		i++;
	}
	return (0);
}
