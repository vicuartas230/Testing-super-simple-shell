#include <stdlib.h>
#include <stdio.h>

extern char **environ;

int main(void)
{
	char *s;

	s = getenv("LOGNAME");
	printf("%s\n", s);
	putenv("LOGNAME=Victor");
	s = getenv("LOGNAME");
	printf("%s\n", s);
	return (0);
}
