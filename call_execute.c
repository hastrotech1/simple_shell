#include "shell.h"

/**
* call_and_execute - this function executes the command passed in from
* the command line.
* @args: command line arguments to be recived and executed.
* Return: returns -1 and aprropiate error on failure, else it execues.
*/

void call_and_execute(char *args[]);

void call_and_execute(char *args[])
{
	pid_t pid_fork_val;

	int wt_status_sig;

	pid_fork_val = fork();

	if (pid_fork_val == -1) /*Potential error in creating a child*/
	{
		perror("Fork Error");

		exit(EXIT_FAILURE);
	}

	if (pid_fork_val == 0) /*This indicates the child process*/
	{
		/*condition checks if user entered full path*/
		if (strchr(args[0], '/') != NULL)
		{
		/*Validate the command recived before executing*/
			if (execve(args[0], args, environ) == -1)
			{
				perror("Error from execlp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			char *path = cstm_getenv("PATH");

			char *token = cstm_strtok(path, ":");

			while (token != NULL)
			{
				char executable_file[MAX_INPUT_SIZE];

				strcpy(executable_file, token);
				strcat(executable_file, "/");
				strcat(executable_file, args[0]);

				if (access(executable_file, X_OK) != -1)
				{
					execve(executable_file, args, environ);
				}

				token = cstm_strtok(NULL, ":");
			}
			perror("nO compatible search");
			exit(EXIT_FAILURE);
		}

	}
	else
	{
		do {

			waitpid(pid_fork_val, &wt_status_sig, WUNTRACED);
		} while (!WIFEXITED(wt_status_sig) && !WIFSIGNALED(wt_status_sig));
	}
}
