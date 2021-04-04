#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

char *_getenv(char *var)
{
	unsigned int l = strlen(var);
	char *pos = NULL, *str = NULL;

	while(*environ)
	{
		str = *environ;
		pos = strchr(str, '=');
		if (pos && (pos - str == l && !strncmp(str, var, l)))
			return pos + 1;
		environ++;
	}
	return (NULL);
}

int main(void)
{
	char *s;

	s = _getenv("LORS");
	printf("%s\n", s);

	return 0;
}
