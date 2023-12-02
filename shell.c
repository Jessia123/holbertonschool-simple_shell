#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

int main(int argc, char *argv[])
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    pid_t pid;
    char *args[2];

    if (argc > 1)
    {
        args[0] = argv[1];
        args[1] = NULL;
        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            execv(args[0], args);

            /* If we get here, execv failed */
            perror(args[0]);
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(NULL);
        }

        return 0;
    }
}

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    pid_t pid;
    char *args[2];

    while (1)
    {
        printf("> ");
        read = getline(&line, &len, stdin);

        if (read == -1)
        {
            if (feof(stdin))
            {
                printf("\n");
                exit(EXIT_SUCCESS);
            }
            else
            {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        /* Remove trailing newline */
        line[strcspn(line, "\n")] = 0;

        /* Skip empty lines */
        if (strlen(line) == 0)
        {
            continue;
        }

        args[0] = line;
        args[1] = NULL;
        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
    }
}
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