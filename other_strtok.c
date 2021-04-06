* C program to count no of words from given input string. */
#include <stdio.h>

#define OUT 0
#define IN 1

// returns number of words in str
char *countWords(char *str)
{
	static int idx = 0;
	int state = OUT, i = idx, j = 0;
	char *b;
	unsigned wc = 0; // word count

	b = malloc(30 * sizeof(char));
	// Scan all characters one by one
	while (str[i])
	{
	        // If next character is a separator, set the
	        // state as OUT
	        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			state = OUT;

	        // If next character is not a word separator and
	        // state is OUT, then set the state as IN and
	        // increment word count
	        else if (state == OUT)
		{
			state = IN;
			while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			{
				b[j] = str[i];
				i++;
				j++;
			}
			if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
				b[j] = '\0';
			++wc;
			idx = i;
			return (b);
		}

	        // Move to next character
	        ++i;
	}
	//b[0] = '\0';
	return ('\0');
}

// Driver program to tes above functions
int main(void)
{
	char str[] = "    One two         three\n four\tfive ";
	char *s = countWords(str);

	while (s)
	{
		printf("%s\n", s);
		//free(str);
		s = countWords(str);
	}
	return 0;
}
