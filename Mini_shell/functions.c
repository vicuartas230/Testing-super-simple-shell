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
			idx = i;
			return (b);
		}
		++i;
	}
	return ('\0');
}

char **fill2pointer(int words, char *s)
{
	char **tok = NULL, *t = NULL;
	int i = 0;

	tok = malloc(words * sizeof(char *));
	while (i < words)
	{
		t = _strtok(s, " "); /*_strtok is not returning the full tokens*/
		printf("t: %s\n", t);
		tok[i] = malloc(_strlen(t) * sizeof(char));
		_strcpy(tok[i], t);
		printf("ciclo: %s\n", tok[i]);
		i++;
	}
	printf("fill: %s\n", tok[0]);
	printf("fill: %s\n", tok[1]);
	printf("fill: %s\n", tok[2]);
	return (tok);
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

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i + 1);
}
