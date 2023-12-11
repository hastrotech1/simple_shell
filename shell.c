#include "shell.h"

/**
 * main - entry point for the simple shell program
 *
 * Return: 0 on sucess.
 */
int main(void)
{
	size_t bufsize = 10;
	char *input_buf = NULL;

	while (true)
	{
		disprompt();
		if (getline(&input_buf, &bufsize, stdin) == -1)
		{
			break;
		}
		else
		{
			printf("%s", input_buf);
		}
	}
	free(input_buf);
	return (0);
}
