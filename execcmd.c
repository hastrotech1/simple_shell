#include "shell.h"

/**
 * execcmd - executes valid and some built-in commands
 * @token - pointer to an array of tokenized input
 *
 * Return: 0 on success.
 */
int execcmd(char* token)
{
	const char *ref_card[] = {"ls", "echo", "cp", "exit", NULL};
	int x;
	pid_t child;
	pid_t main;

	for (x = 0; ref_card[x] != NULL; x++)
	{
		if (strcmp(token[0], ref_card[x]) == 0)
		{
			child = fork();
			if (child < 0)
			{
				perror("unable to fork child");
				exit(EXIT_FAILURE);
			}
			else
			{
				int failchk = execve(token[0], token, NULL);
				if (failchk == -1)
				{
					printer("%s:ExecuteError\n", token[0]);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
