#include <stdio.h>

extern char **environ;

int main(int ac, char **av, char **global)
{
	unsigned int i;

	for (i = 0; global[i] != '\0'; i++)
	{
		printf("%p\n", global[i]);
		printf("%p\n\n", environ[i]);
	}
	return (0);
}
