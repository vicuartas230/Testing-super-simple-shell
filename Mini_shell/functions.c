#include "header.h"

char *_strchr(char *s, char c)
{
	int a;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (c == s[a])
		{
			return (&(s[a]));
		}
	}
	if (c == s[a])
	{
		return (&(s[a]));
	}
	return ('\0');
}

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

char *_strtok(char *str, const char *delim)
{
	static int idx = 0;
	int state = 0, i = idx, j = 0;
	char *b;
	unsigned wc = 0;

	b = malloc(1024 * sizeof(char));
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == delim[0])
			state = 0;
		else if (state == 0)
		{
			state = 1;
			while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != delim[0])
			{
				b[j] = str[i];
				i++;
				j++;
			}
			if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == delim[0])
				b[j] = '\0';
			++wc;
			idx = i;
			printf("%s\n", b);
			return (b);
		}
		++i;
	}
	return ('\0');
}

char **fill2pointer(int words, char *s)
{
	char **a, *t;
	int i = 0, j;

	a = malloc(words * sizeof(char *));
	while (i < words)
	{
		t = _strtok(s, " ");
		printf("%s\n", t); /*_strtok is not returning the tokens full*/
		a[i] = malloc((_strlen(t) + 1) * sizeof(char));
		_strcpy(a[i], t);
		printf("%s\n", a[i]);
		i++;
	}
	return (a);
}

int counter_words(char * buff)
{
	int state = 0;
	unsigned wc = 0; // word count

	while (*buff)
	{
	        if (*buff == ' ' || *buff == '\n' || *buff == '\t')
			state = 0;
	        else if (state == 0)
		{
			state = 1;
			++wc;
		}
	        ++buff;
	}
	return wc;
}

char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; a <= _strlen(src); a++)
	{
		dest[a] = src[a];
	}
	return (dest);
}

int _strlen(char *s)
{
	int i;

	for (i = 0; *s; i++)
		s++;
	return (i);
}
