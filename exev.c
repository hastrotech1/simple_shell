#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *tok(const char *input_buf)
{
    int x = 0;
    char *token;
    const char *det[] = {" ", "\n", "\t"}; // Delimiters include space, newline, and tab

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

int main()
{
    char input_buf[100];
    printf("Enter a sentence: ");
    scanf("%99[^\n]", input_buf);

    char *token = tok(input_buf);
    return 0;
}
