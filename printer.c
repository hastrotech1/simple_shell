#include "shell.h"
/**
 * printer - prints to the stdoutput
 * @msg: pointer tto a constant character
 *
 * Return: no return value
 */

void printer(const char *msg)
{
	write(STDOUT_FILENO, msg, strlen(msg));
}
