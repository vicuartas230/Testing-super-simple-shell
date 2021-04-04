#include <stdio.h>
#include <string.h>
#include "user_input.h"

void flush_input()
{
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
		/* skip it */ ;
}

input_status get_user_input(const char *prompt, char *user_input, size_t size)
{
	printf("%s", prompt);

	if (fgets(user_input, size, stdin) == NULL)
		return INPUT_FAILED;

	char *pNewline;
	if ((pNewline = strchr(user_input, '\n')) == NULL)
	{
		flush_input();
		return INPUT_TOOLONG;
	}

	*pNewline = '\0';

	return INPUT_SUCCESSFUL;
}
