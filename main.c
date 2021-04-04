#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_input.h"

#define MAX_STR_LEN 50

int main(int argc, char *argv[])
{
	char user_input[MAX_STR_LEN + 2]; /* +2 for newline character (\n) and terminating null character (\0) */
	input_status status;

	while (1)
	{
		status = get_user_input("Enter your name: ", user_input, sizeof(user_input));

		if (status == INPUT_FAILED)
		{
			fprintf(stderr, "Unable to read user input\n");
			exit(EXIT_FAILURE);
		}

		if (status == INPUT_TOOLONG)
		{
			fprintf(stderr, "Entry exceeds %d characters\n", MAX_STR_LEN);
			continue;
		}

		if (strlen(user_input) == 0)
		{
			fprintf(stderr, "Entry is missing\n");
			continue;
		}

		if (user_input[0] == 0x18) /* user entered Ctrl+X (^x) to cancel */
		{
			fprintf(stderr, "User cancelled\n");
			return 0;
		}

		break;
	}

	printf("User entered:  %s\n", user_input);

	return 0;
}
