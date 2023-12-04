/**
 * @file main.c
 * @brief A simple shell program that takes user commands and executes them.
 * The program displays a prompt, reads the user's command, and executes it using fork and exec.
 * The parent process waits for the child process to complete before displaying the next prompt.
 * The program continues to run until the user enters Ctrl+D (end of file).
 */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main(void)
{
    char command[MAX_COMMAND_LENGTH];
    int status;

    while (1)
    {
        printf("$ "); // Displaying the prompt

        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            if (feof(stdin))
            {
                printf("\n"); // Print newline for better formatting
                break; // Exit the loop on Ctrl+D (end of file)
            }
        }

        // Removing the newline character from the command
        command[strcspn(command, "\n")] = '\0';

        pid_t pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            // Child process executes the command
            if (execlp(command, command, NULL) == -1)
            {
                // If execution fails, print error and exit child process
                perror("execlp");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            // Parent process waits for the child to complete
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
