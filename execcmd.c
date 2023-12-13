#include "shell.h"

/**
 * execcmd - executes valid and some built-in commands
 * @token - pointer to an array of tokenized input
 *
 * Return: 0 on success.
 
int execcmd(char **token)
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
			if (child == 0)
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
				wait(NULL);
			}
		}
	}
	return (0);
}
*/

#include "shell.h"

/**
 * execcmd - executes valid and some built-in commands
 * @token: pointer to a tokenized input
 *
 * Return: 0 on success.
 */

void printer(const char *msg);
int execcmd(char **token)
{
	int x;
	const char *ref_card[] = {"/bin","ls", "echo", "cp", "exit", NULL};
	
	if (token == NULL || *token == NULL)
	{
		char error[] = "Invalid command\n";
		
		write(STDERR_FILENO, error, sizeof(error) - 1);
		
		return (-1);
	}
	
	for (x = 0; ref_card[x] != NULL; x++)
	{
		if (strcmp(*token, ref_card[x]) == 0)
		{
			pid_t child = fork();
			
			if (child < 0)
			{
				perror("Unable to fork child");
				_exit(EXIT_FAILURE);
			}

			if (child == 0)
			{
				char *path = "/bin/";
				char exe_cutable[256];
				char *argv[] = {*token, NULL};
				int failchk = execve(exe_cutable, argv, NULL);

				snprintf(exe_cutable, sizeof(exe_cutable), path, *token);
				
				if (failchk == -1)
				{
					perror("ExecuteError");
					_exit(EXIT_FAILURE);
				}
			}
			else
			{
				waitpid(child, NULL, 0);
			}
		}
	}
	
	return 0;
}

