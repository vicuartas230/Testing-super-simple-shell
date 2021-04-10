#include "header.h"

int main(void)
{
	char *a = NULL, **com = NULL, *e = NULL, **paths = NULL, *dest;
	pid_t child_pid;
	int c, w, p = 1, r, sta, z = 0;
	size_t b = 0;
	struct stat st;
	DIR *dir;
	struct dirent *direntp;

	do{
		z++;
		printf("#cisfun$ ");
		c = getline(&a, &b, stdin);
		if (c != EOF)
		  {
			child_pid = fork();
			if(child_pid == 0)
			{
				w = counter_words(a);
				com = fill2pointer(w, a, " ");
				printf("%s", com[0]);
				printf("%s", com[1]);
				printf("%s", com[2]);
				if(a[0] == '/')
				{
					sta = stat(com[0], &st);
					if (!sta)
					{
						if (execve(com[0], com, NULL) == -1)
							printf("Execve falló");
						exit(1);
					}
					else
						printf("%d : %s\n", z, "Not Found"), exit(-1);
				}
				else
				{
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
					r = execve(dest, com, NULL);
					if (r == -1)
					{
						printf("%d : %s\n", z, "Not found");
						exit(-1);
					}
					exit(1);
				}
			}
			else if (child_pid == -1)
				printf("ERROR\n");
			else
				wait(NULL);
		}
/*		free_2p(com);
		free_2p(paths);*/
	} while (c != EOF);
	printf("\n");
	free(a);
	return (0);
}
