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
	size_t a, e;

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

char *_strtok(char *str, const char *delim)
{
	static int idx = 0;
	int state = 0, i = idx, j = 0;
	char *b;

	b = malloc(50 * sizeof(char));
	if (b == NULL)
		return (NULL);
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

char **fill2pointer(int words, char *s, char *delim)
{
	char **tok = NULL, *t = NULL;
	int i = 0;

	tok = malloc((words + 1) * sizeof(char *));
	if (tok == NULL)
		return (NULL);
	while (i < words)
	{
		t = _strtok(s, delim);
		tok[i] = malloc(_strlen(t) * sizeof(char));
		if (tok[i] == NULL)
		{
			while (i >= 0)
			{
				free(tok[i]);
				i--;
			}
			free(tok);
		}
		_strcpy(tok[i], t);
		i++;
	}
	tok[i] = NULL;
	return (tok);
}

void free_2p(char **com)
{
	while (*com)
	{
		free(*com);
		com++;
	}
	free(com);
}

int counter_words(char * buff)
{
	int state = 0;
	unsigned wc = 0;

	while (*buff)
	{
	        if (*buff == ' ' || *buff == '\n' || *buff == '\t' || *buff == ':')
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

char *_getenv(const char *var)
{
	unsigned int l = (_strlen((char *)var) - 1);
	char *pos = NULL, *str = NULL;

	while(*environ)
	{
		str = *environ;
		pos = _strchr(str, '=');
		if (pos && (pos - str == l && !_strncmp(str, (char *)var, l)))
			return pos + 1;
		environ++;
	}
	return (NULL);
}

char *_strcat(char *dest, char *src)
{
	int i, j, contador;

	contador = 0;
	for (i = 0 ; dest[i] != '\0' ; i++)
	{
		contador++;
	}
	for (j = 0 ; src[j] != '\0' ; j++)
	{
		dest[contador + j] = src[j];
	}
	dest[contador + j] = '\0';
	return (dest);
}
