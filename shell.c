#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(void)
{
	pid_t child_pid;
	int c, r;
	char *argv[] = {NULL, NULL, NULL}, *a = NULL;
	size_t b = 0;

	do{
		printf("#cisfun$ ");
		if ((c = getline(&a, &b, stdin)) != '\n')
		{
			child_pid = fork();
			wait(NULL);
			if(child_pid == 0)/* child process*/
			{
				a[c - 1] = 0;
				argv[0] = a;
/*				argv[1] = "";*/
				r = execve(argv[0], argv, NULL);
/*			if (r == -1)
			kill(child_pid, SIGSTOP);*/
					exit(1);
			}
			else if (child_pid == -1)
				printf("ERROR\n");
		}
	} while (c != EOF);
	free(a);
}
