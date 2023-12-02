/**
 * @file shell.c
 * @brief A simple shell program that executes a command passed as a command line argument.
 *
 * This program takes a command as a command line argument and executes it using the `execv` function.
 * It forks a child process, and the child process uses `execv` to execute the command.
 * The parent process waits for the child process to complete using the `wait` function.
 *
 * @param argc The number of command line arguments.
 * @param argv An array of strings containing the command line arguments.
 * @return 0 on success, -1 on failure.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include<shell.h>

int main(int argc, char *argv[]) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    pid_t pid;
    char *args[2];

    if (argc > 1) {
        args[0] = argv[1];
        args[1] = NULL;
        pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            execv(args[0], args);

            /* If we get here, execv failed */
            perror(args[0]);
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
        }

        return 0;
    }
}



/**
 * main - Entry point for the shell program
 *
 * Description:
 * This function serves as the entry point for the shell program.
 * It initializes the shell, reads user input, and executes commands accordingly.
 *
 * Return:
 * 0 on success, -1 on failure
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    pid_t pid;
    char *args[2];

    while (1) {
        printf("> ");
        read = getline(&line, &len, stdin);

        if (read == -1) {
            if (feof(stdin)) {
                printf("\n");
                exit(EXIT_SUCCESS);
            } else {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        /* Remove trailing newline */
        line[strcspn(line, "\n")] = 0;

        /* Skip empty lines */
        if (strlen(line) == 0) {
            continue;
        }

        args[0] = line;
        args[1] = NULL;
        pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            execv(args[0], args);

            /* If we get here, execv failed */
            perror(args[0]);
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
        }
    }

    free(line);
    return 0;
}