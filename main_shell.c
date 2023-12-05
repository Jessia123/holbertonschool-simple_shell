#include "shell.h"

/**
 * main - Entry point for the simple shell program
 *
 * Description: This function creates a simple shell that continuously prompts
 * the user for commands, reads the input, and executes commands until the
 * user exits.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	do 
	{
		printf("($) ");
		line = read_line();
		args = split_line(line);
		status = execute(args);

		free(line);
		free(args);
	}
	while (status);

	return (0);
}
