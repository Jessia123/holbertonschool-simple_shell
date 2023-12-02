#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h" /* Assuming shell.h contains necessary function prototypes or constants */

/**
 * main - Main function for executing shell commands.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
    pid_t pid;
    char *args[2];

    /* Check if arguments are provided */
    if (argc > 1)
    {
        args[0] = argv[1]; /* Set the command to be executed */
        args[1] = NULL;    /* Null-terminate the argument list */

        pid = fork(); /* Create a new process */

        /* Check for fork() failure */
        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        /* Child process */
        if (pid == 0)
        {
            /* Execute the command */
            execv(args[0], args);

            /* If we get here, execv failed */
            perror(args[0]);
            exit(EXIT_FAILURE);
        }
        else /* Parent process */
        {
            wait(NULL); /* Wait for the child process to finish */
        }
    }
    else
    {
        args[0] = "default_command"; /* Set a default command */
        args[1] = NULL;              /* Null-terminate the argument list */

        /* If we get here, execv failed */
        perror(args[0]); /* No command provided, so print an error */
        exit(EXIT_FAILURE);
    }

    return 0;
}