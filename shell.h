#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Function prototypes */
char *read_line(void);
char **split_line(char *line);
int execute(char **args);

#endif /* SHELL_H */
