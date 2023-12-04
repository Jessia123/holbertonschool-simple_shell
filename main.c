#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *buf = NULL;
    size_t count = 0;
    ssize_t nread;

    (void)argc, (void)argv;

    write(STDOUT_FILENO, "MyShell$ ", 9);
    nread = getline(&buf, &count, stdin);

    if (nread ==  -1)
    {
         perror("Exiting shell");
         exit(1);
    }
    printf("%s", buf);
}