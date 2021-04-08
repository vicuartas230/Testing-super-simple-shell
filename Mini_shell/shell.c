#include "header.h"

int main(void)
{
	char *a = NULL, *s = NULL, **com;
	pid_t child_pid;
	int c, i = 1, j = 0, w;
	size_t b = 0;

	do{
		printf("#cisfun$ ");
		c = getline(&a, &b, stdin);
		if (c != EOF)
		  {
			child_pid = fork();
			wait(NULL);
			if(child_pid == 0)
			{
				a[c] = 0;
				w = counter_words(a);
				com = fill2pointer(w, a);
				printf("main: %s\n", com[0]);
				printf("main: %s\n", com[1]);
				printf("main: %s\n", com[2]);
				if (execve(com[0], com, NULL) == -1)
					printf("Execve Error\n");
				exit(1);
			}
			else if (child_pid == -1)
				printf("ERROR\n");
		}
	} while (c != EOF);
	free(a);
}
