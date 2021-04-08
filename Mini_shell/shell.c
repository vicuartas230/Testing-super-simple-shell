#include "header.h"

int main(void)
{
	char *a = NULL, *s = NULL, **com, *e = NULL, **paths = NULL, *dest;
	pid_t child_pid;
	int c, i = 1, j = 0, w, p = 1, r;
	size_t b = 0;
	struct stat st;
	DIR *dir;
	struct dirent *direntp;

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
				com = fill2pointer(w, a, " ");
				e = _getenv("PATH");
				w = counter_words(e);
				paths = fill2pointer(w, e, ":");
				while (paths[p])
				{
					dir = opendir(paths[p]);
					while((direntp = readdir(dir)) != NULL)
					{
						if (strcmp(direntp->d_name, com[0]) == 0)
						{
							_strcat(paths[p], "/");
							dest = _strcat(paths[p], com[0]);
							break;
						}
					}
					closedir(dir);
					p++;
				}
				if (execve(dest, com, NULL) == -1)
					printf("Execve Error\n");
				exit(1);
			}
			else if (child_pid == -1)
				printf("ERROR\n");
		}
	} while (c != EOF);
	free(a);
}
