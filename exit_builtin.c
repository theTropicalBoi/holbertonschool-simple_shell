#include "main.h"

/**
 * _exit_builtin - builtin exit
 *
 * @array_of_tokens: command array
 *
 * Return: O if failure 1 if success
 */

int _exit_builtin(char **array_of_tokens)
{
if (array_of_tokens[1] != NULL)
exit(atoi(array_of_tokens[1]));
else
return(EXIT_CODE);
}
