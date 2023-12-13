#include "shell.h"

/**
 * main - entry point for the simple shell program
 *
 * Return: 0 on success.
 */
int main(void)
{
	char *token;
	size_t bufsize = 10;
	char *input_buf = NULL;

	while (1)
	{
		disprompt();
		if (getline(&input_buf, &bufsize, stdin) == 0)
		{
			token = tok(input_buf);
			if (token != NULL)
			{
				execcmd(&token);
			}
			free(token);			
		}
		else
		{
			break;				
		}
	}
	free(input_buf);
	return (0);
}
