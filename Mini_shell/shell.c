#include "header.h"

int main(void)
{
	char *a = NULL, *s = NULL, **com;
	pid_t child_pid;
	int c, i = 1, j = 0, w;
	size_t b = 0;

	do{
		printf("#cisfun$ ");
		/*if (( != '\n')
		  {*/
			child_pid = fork();
			wait(NULL);
			if(child_pid == 0)
			{
				c = getline(&a, &b, stdin);
				a[c - 1] = 0;
				w = counter_words(a);
				com = fill2pointer(w, a);
				printf("%s\n", com[0]);
				execve(com[0], com, NULL);
				exit(1);
			}
			else if (child_pid == -1)
				printf("ERROR\n");
//		}
	} while (c != EOF);
	free(a);
}
