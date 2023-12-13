#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Custom getline function
 */

char *custom_getline(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;

    	/**
	 * Read a line of input from the user
	 */

 	characters = getline(&buffer, &bufsize, stdin);
	if (characters == -1)
	{
 	perror("getline error");
 	exit(EXIT_FAILURE);
 	 }

    	/**Remove the newline character at the end
	 */

	if (characters > 0 && buffer[characters - 1] == '\n')
	{
	buffer[characters - 1] = '\0';
	}

    	/**Resize the buffer to fit the actual content
	 */

	buffer = realloc(buffer, characters);
	if (buffer == NULL) {
	perror("realloc error");
	exit(EXIT_FAILURE);
	}
	return buffer;
}
