#include "shell.h"

/**
 * tok - This function tokinizes the command to separete the
 * command and it's arguments using the strtok function.
 *
 * @input_buf: The string to be tokinized when inputed
 *
 * Return: returns token as output when successfully tokenized
 */

char *tok(const char *input_buf)
{
	int x = 0;
	char *token;
	/**
	 * Delimeters include space, newline, and tab
	 */
	const char *det[] = {" ", "\n", "\t"};
	
	if (input_buf == NULL)
	{
		printf("No valid command\n");
		return NULL;
	}
	else
	{
		token = strtok((char *)input_buf, *det);
		while (token != NULL)
		{
			printf("%s\n", token);
			token = strtok(NULL, *det);
			x++;
		}
	}
	return token;
}

/**
 * main - The main function to combine all the custom and
 * helper functions together.
 *
 * Return: Gives 0 as output when successful
 */

int main()
{
	char input_buf[100];

	printf("Enter a sentence: ");
	scanf("%99[^\n]", input_buf);
	
	char *token = tok(input_buf);
	return 0;
}
