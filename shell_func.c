#include "shell.h"
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * read_line - Read a line of input from the user.
 *
 * Return: A pointer to the input line.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return (line);
}

/**
 * split_line - Split a string into tokens.
 * @line: The input string to split.
 *
 * Return: An array of pointers to the tokens.
 */
char **split_line(char *line)
{
	int bufsize = BUFFER_SIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\n");
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * execute - Execute a command.
 * @args: An array of arguments, including the command itself.
 *
 * Return: 1 if the shell should continue, 0 if it should exit.
 */
int execute(char **args)
{
	pid_t pid;
	pid = fork();
	

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		wait(NULL);
	}
	return (1);
}


