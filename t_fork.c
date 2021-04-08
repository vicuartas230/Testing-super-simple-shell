#include <unistd.h>
#include <stdio.h>

int main() {
	int pid;

	pid = fork();
	wait(NULL);
	if (pid == 0)
	{
		printf("%s\n", "Child Process");
		sleep(3);
	}
	else
		printf("%s\n", "Parent Process");
	return 0;
}
