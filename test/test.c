#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	char *args[MAX_ARGS];
	pid_t pid;
	int arg_count;
	char *token;

	while (1)
	{
		printf("$ ");
		if (getline(&input, &input_size, stdin) == -1)
			break;

		input[strcspn(input, "\n")] = 0;

		arg_count = 0;

		token = strtok(input, " ");
		while (token != NULL && arg_count < MAX_ARGS - 1)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		pid = fork();
		if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror(".//shell:");
				exit(EXIT_FAILURE);
			}
		} else if (pid < 0)
			perror(".//shell:");
		else
			wait(NULL);
	}

	free(input);
	return 0;
}
