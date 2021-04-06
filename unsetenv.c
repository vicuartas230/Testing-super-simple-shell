#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

extern char **environ;

int _strncmp(char *s1, char *s2, size_t n)
{
	int a, e;

	for (a = 0; a < n; a++)
	{
	        if (s1[a] != s2[a])
		{
			e = (s1[a] - s2[a]);
			break;
		}
	        else
		{
			e = (0);
		}
	}
	return (e);
}

int _unsetenv(const char *name)
{
	char **ep, **sp, *a, *b, *c, *d;
	size_t len, i;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
	        return -1;

	for (i = 0; name[i] !=  '\0'; i++)
		;
	ep = environ;
	while (*ep)
	{
		if (!(_strncmp(*ep, (char *)name, i)) && (*ep)[i] == '=')
		{
			sp = ep;
			while (*sp)
			{
				*sp = *(sp + 1);
				sp++;
			}
		}
		else
			ep++;
	}
	return (0);
}

int main()
{
	char *s;

	setenv("LAST", "/etc/shadow", 1);
	s = getenv("LAST");
	printf("%s\n", s);
	unsetenv("LAST");
	s = getenv("LAST");
	printf("%s\n", s);
	return 0;
}
