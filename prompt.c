#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	char *a = NULL;
	ssize_t b = 0, c;
	int i = 0;
/*	FILE *stream;

	stream = fopen(av[1], "r");*/
	do{
		printf("$ ");
		if (c = getline(&a, &b, stdin) != '\n') 
		{
			while (a[i])
			{
				write(STDOUT_FILENO, &(a[i]), c);
				i++;
			}
			if (feof(stdin))
				exit(EXIT_SUCCESS);
			else
			{
				perror("readline");
				exit(EXIT_FAILURE);
			}
		}
	}while (1);
/*	fclose(stream);*/
	return (0);
}
