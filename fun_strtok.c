#include <stdio.h>
#include <string.h>
#include <malloc.h>

char* my_strtok(char* s, char* delm)
{
	static int currIndex = 0;
	if(!s || !delm || s[currIndex] == '\0')
		return NULL;
	char *W = (char *)malloc(sizeof(char)*1024);
	int i = currIndex, k = 0, j = 0;

	while (s[i] != '\0')
	{
	        j = 0;
	        while (delm[j] != '\0'){
			if (s[i] != delm[j])
				W[k] = s[i];
			else
			{
				W[k] = 0;
				currIndex = i+1;
				//Iterator = ++ptr;
				return W;
			}
			j++;
		}

	        i++;
	        k++;
	}
	if (!(s[i]))
	{
		W[k] = 0;
		return W;
	}
}

int main(void)
{
	char s[] = "       Hello        Betty                    Holberton";
	char delm[] = " ";
	//char newstr[100];
	int i, j = 0, k = 0;

	char *str2 = strtok(s, delm);
	printf("%s\n", str2);
	char *str = my_strtok(s, delm);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			k++;
	}
	while(j < k + 1){
	        printf("%s\n", str);
	        free(str);
	        str = my_strtok(s, delm);
	        j++;
	}
	free(str);
	return 0;
}
