#include "shell.h"

/**
 * tok - Tokenizes the command to separate the command and its arguments
 * @input_buf: The string to be tokenized when inputted
 *
 * Return: returns token as output when successfully tokenized
 */

char *tok(const char *input_buf)
{
    static char *token;
    static const char *input;
    static int index;
    int i = 0;

    const char *delimiters = " \n\t";

    if (input_buf != NULL)
    {
        input = input_buf;
        index = 0;
    }

    if (input == NULL || *input == '\0')
    {
        char error[] = "No valid command\n";
        write(STDERR_FILENO, error, sizeof(error) - 1);
        return NULL;
    }

    token = (char *)malloc(strlen(input) + 1);
    if (token == NULL)
    {
        perror("Malloc failed");
        _exit(EXIT_FAILURE);
    }

    while (input[index] && !strchr(delimiters, input[index]))
    {
        token[i++] = input[index++];
    }
    token[i] = '\0';

    while (input[index] && strchr(delimiters, input[index]))
    {
        index++;
    }

    return token;
}

