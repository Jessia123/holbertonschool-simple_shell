#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 100 /* Maximum number of arguments */
/**
 * main - Entry point for the shell program
 *
 * Description: Implements a simple shell that reads commands
 *              from the user, tokenizes them, and executes
 *              using the execve system call in child processes.
 *
 * Return: Always returns 0 on successful completion.
 */
int main(void) {
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t characters;
    char *token;
    char *args[MAX_ARGS];
    int i;
    pid_t pid; /* Declare pid at the start of the block */

    while (1) {
        /* Displaying the prompt */
        printf("$ ");
        characters = getline(&buffer, &bufsize, stdin);

        /* Error handling for getline */
        if (characters == -1) {
            if (feof(stdin)) {
                printf("\n");
                break; /* Exit loop on Ctrl+D (end of file) */
            } else {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        /* Remove newline character */
        buffer[strcspn(buffer, "\n")] = '\0';

        token = strtok(buffer, " ");
        i = 0; /* Reset i for each loop iteration */

        /* Tokenize input into command and arguments */
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; /* Set the last element to NULL for execve */

        pid = fork(); /* Assign value to pid at the start of the block */

        /* Error handling for fork */
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        /* Child process executes the command */
        if (pid == 0) {
            if (execve(args[0], args, NULL) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else { /* Parent process waits for child */
            int status;
            waitpid(pid, &status, 0);
        }
    }

    free(buffer);
    return EXIT_SUCCESS;
}
