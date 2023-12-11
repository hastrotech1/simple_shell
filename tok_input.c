#include "shell.h"

/**
 * tok_input - This function tokinize the command to separete the
 * command and its arguments using the strtok function.
 *
 * @_str: The input string to be tokinized.
 *
 * Return: return token  as output when successful.
 */

char **tok_input(char *_str)
{
	const char *deli = "\n\t";
	char *tok = strtok(_str, deli);
	char **token = NULL;
	size_t tok_count = 0;

	while (tok != NULL)
	{
		token = realloc(token, sizeof(char *) * (tok_count + 1));
		if (token == NULL)
		{
			perror("Allocation Failed");
			exit(EXIT_FAILURE);
		}
		token[tok_count++] = strdup(tok);
		if (token[tok_count - 1] == NULL)
		{
			perror("Token Failed");
			exit(EXIT_FAILURE);
		}
		tok = strtok(NULL, deli);
	}
	token = realloc(token, sizeof(char *) * (tok_count + 1));
	if (token == NULL)
	{
		perror("Failed Memory Allocation");
		exit(EXIT_FAILURE);
	}
	token[tok_count] = NULL;
	return (token);
}
