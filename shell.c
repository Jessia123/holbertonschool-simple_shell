#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 100

/*
 * main - Entry point for the shell program
 *
 * Description: Implements a simple shell that reads commands
 *              from the user, tokenizes them, and executes
 *              using the execve system call in child processes.
 *
 * Return: Always returns 0 on successful completion.
 */
int main(void)
{
    char *buffer = NULL;        /* Buffer to store user input */
    size_t bufsize = 0;         /* Size of the buffer */
    ssize_t characters;         /* Number of characters read */
    char *token;                /* Tokenized input */
    char *args[MAX_ARGS];       /* Array to store command and arguments */
    int i;                      /* Loop variable */
    pid_t pid;                  /* Process ID */

    while (1)
    {
        printf("$ "); /* Display prompt */
        characters = getline(&buffer, &bufsize, stdin); /* Read user input */

        if (characters == -1)
        {
            if (feof(stdin))
            {
                printf("\n");
                break;
            }
            else
            {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        buffer[strcspn(buffer, "\n")] = '\0'; /* Remove newline character */

        token = strtok(buffer, " ");
        i = 0;

        /* Tokenize input into command and arguments */
        while (token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; /* Set the last element to NULL for execve */

        pid = fork(); /* Create child process */

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            /* Child process executes the command */
            if (execve(args[0], args, NULL) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            /* Parent process waits for child */
            int status;
            waitpid(pid, &status, 0);
            printf("\n"); /* Display newline after command execution */
        }
    }

    free(buffer);
    return EXIT_SUCCESS;
}