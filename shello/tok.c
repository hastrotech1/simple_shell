#include "shell.h"

/**
 * tok - Tokenizes the command to separate the command and its arguments
 * @input_buf: The string to be tokenized when inputted
 *
 * Return: returns token as output when successfully tokenized
 *

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
*/

char *cstm_strtok(char *str, const char *delim);

char *cstm_strtok(char *str, const char *delim)
{
        static char *next_token;

        char *new_token;

        if (str != NULL)
        {
                /*Updates the next value of the string*/
                next_token = str;
        }

        /*Check for the end of tokens in the string*/
        if (next_token == NULL || *next_token == '\0')
        {
                /*End of the string null is returned*/
                return (NULL);
        }

        while (*next_token != '\0' && strchr(delim, *next_token) != NULL)
        {
                next_token++;
        }

        /*check for end of tokens*/

        if (*next_token == '\0')
        {
                return (NULL);
        }

        new_token = next_token;

        while (*next_token != '\0' && strchr(delim, *next_token) == NULL)
        {
                next_token += 1;
        }

        if (*next_token != '\0')
        {
                *next_token = '\0';

                next_token += 1;
        }

        /*All strings has been tokenized completely */
        return (new_token);
}
