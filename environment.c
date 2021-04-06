#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

char *_getenv(const char *var)
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

char *fill(const char *name, const char *value)
{
	unsigned int i = 0;
	char *buff = NULL;

	buff = malloc((strlen(name) + strlen(value) + 2) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	while(*name)
	{
		buff[i] = *name;
		name++;
		i++;
	}
	buff[i] = '=';
	i++;
	while (*value)
	{
		buff[i] = *value;
		value++;
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

int _setenv(const char *name, const char *value, int overwrite)
{
	char *s = _getenv(name);

	if (s == NULL || overwrite > 0)
	{
		putenv(fill(name, value));
	}
	return (0);
}

int main(void)
{
	char *s = NULL;
	int a;

	setenv("LAST", "/usr/bin", 1);
	s = getenv("LAST");
	printf("LAST: %s\n", s);
	setenv("LAST", "/etc/passwd", 1);
	s = getenv("LAST");
	printf("LAST: %s\n", s);
	a = setenv("LAT", "/etc/shadow", 1);
	printf("a: %d\n", a);
	s = getenv("LAT");
	printf("LAT: %s\n", s);
/*	_setenv("LAST", "/usr/bin", 1);
	s = _getenv("LAST");
	printf("LAST: %s\n", s);
	_setenv("LAST", "/etc/passwd", 1);
	s = _getenv("LAST");
	printf("LAST: %s\n", s);
	_setenv("LAT", "/etc/passwd", 0);
	s = _getenv("LAT");
	printf("LAT: %s\n", s);*/
	printf("--------------------------\n");
	while (*environ)
	{
		printf("%s\n", *environ);
		environ++;
	}
	return (0);
}
