#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    char *buffer;
    size_t bufsize = 1024; /* Initial buffer size */
    ssize_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("$ "); /* Displaying the prompt */
        characters = getline(&buffer, &bufsize, stdin);

        if (characters == -1) {
            if (feof(stdin)) {
                printf("\n");
                break; /* Exit the loop on Ctrl+D (end of file) */
            } else {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        buffer[strcspn(buffer, "\n")] = '\0'; /* Removing newline character */
    }

    free(buffer);
    return EXIT_SUCCESS;
}
