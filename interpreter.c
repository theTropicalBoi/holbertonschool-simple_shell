#include "main.h"
/**
 * shell_interpreter - main block
 * Return: 0
 */
void shell_interpreter(void)
{
		size_t n = 0;
		char *buf = NULL;

		printf("$");
		getline(&buf, &n, stdin);
		printf("%s", buf);
		printf("Buffer size: %ld\n", n);

		free(buf);
		return (0);
}

/**
 * no_shell_interpreter - 
 */
void no_shell_interpreter(void)
{
	
}
