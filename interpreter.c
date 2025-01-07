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
	size_t n = 0;
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
        // Child process
        char *args[MAX_ARGS];
        args[0] = command;
        args[1] = NULL;

        if (execve(command, args, environ) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}