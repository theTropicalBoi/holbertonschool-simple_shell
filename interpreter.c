#include "main.h"
/**
 * shell_interpreter - main block
 * Return: 0
 */
void shell_interactive(void)
{
		char *line = NULL;
		size_t len = 0;
   		ssize_t read;

		while (1) {
			printf("$ ");
			read = getline(&line, &len, stdin);

			if (read == -1) {
				printf("\n");
				break;
			}

			line[strcspn(line, "\n")] = 0;

			if (strlen(line) == 0)
				continue;

			if (execute_command(line) == -1)
				printf("%s: command not found\n", line);
		}

	free(line);
}

/**
 * no_shell_interpreter - 
 */
void no_shell_interactive(void)
{
	char *buf = NULL;

	if (buf) {
		free(buf);
	}
}

int execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1) {
		perror("fork");
		return -1;
	} else if (pid == 0) {
		char *args[MAX_ARGS];
		args[0] = command;
		args[1] = NULL;

		if (execve(command, args, environ) == -1) {
			perror("execve");
			exit(EXIT_FAILURE);
		}
	} else {
		int status;
		waitpid(pid, &status, 0);
	}

	return 0;
}

/**
 * execute_command - executes a command based on it's type
 * Return: void
 */
void execute_command(char *input)
{
char *args[MAX_CMD_LENGTH];
char *token;
int i = 0;

token = strtok(input, " \t\r\n");
while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " \t\r\n");
}
args[i] = NULL;

if (args[0] == NULL)
{
printf("No command entered.\n");
return;
}
if (execvp(args[0], args) == -1) 
{
perror("Error executing command");
}
}

int main() 
{
char input[MAX_CMD_LENGTH];

while (1)
{
printf("$ ");
if (fgets(input, sizeof(input), stdin) == NULL)
{
perror("Error reading input");
continue;
}
input[strcspn(input, "\n")] = '\0';

if (strcmp(input, "exit") == 0) 
{
break;
}
execute_command(input);
}
return 0;
}
