#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	char *token[];
	
	char *det  = " ";
	
	if (input_buf == NULL)
	{
		perror("No valid command");
		return NULL;
	}
	else
	{
		token[0] = strtok((char *)input_buf, *det);
		while (token != NULL)
		{
			token = strtok(NULL, *det);
			x++;
		}
	}
	return (token);
}
