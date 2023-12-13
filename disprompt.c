#include "shell.h"

/**
 * disprompt - displays preferred prompt on the terminal.
 *
 * Return: void.
 */
void disprompt(void)
{
	char prompt[] = "kind_Hastro$";
	write(STDOUT_FILENO, prompt, sizeof(prompt) -1);
}
