#include "main.h"
/**
 * 
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
		shell_interactive();
	else
		no_shell_interactive();

	return (0);
}
