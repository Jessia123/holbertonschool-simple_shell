#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

int main(int argc, char *argv[]) {
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
    } else {
        /* If we get here, execv failed */
        perror(args[0]);
        exit(EXIT_FAILURE);
    }

    return 0;
}
