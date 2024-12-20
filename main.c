#include "main.h"
/**
 * 
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
		shell_interpreter();
	else
		no_shell_interpreter();

	return (0);
}
