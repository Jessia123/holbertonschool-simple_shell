#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 100 // Maximum number of arguments

/**
 * main - Simple Shell
 * Description: Basic UNIX command-line interpreter
 * Return: Always 0
 */
int main(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    while (1)
    {
        // Displaying the prompt
        printf("$ ");
        characters = getline(&buffer, &bufsize, stdin);

        // Error handling for getline
        if (characters == -1)
        {
            if (feof(stdin))
            {
                printf("\n");
                break; // Exit loop on Ctrl+D (end of file)
            }
            else
            {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        // Remove newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        char *token;
        char *args[MAX_ARGS]; // Array to store command and arguments

        token = strtok(buffer, " ");
        int i = 0;
