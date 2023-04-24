#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
* main - entry point
* @void: void
* Return: Command line
*/

int main()
{
	size_t MAXLINE = 10;

	char prompt[] = "SIA> ";

	int num = 0;

	char *cmdline = malloc(sizeof(char) *  MAXLINE);




	while (1)
	{


		_printf("%s", prompt);
		
		num = getline(&cmdline, &MAXLINE, stdin);
		
		if (num == EOF)
		{
		free(cmdline);
		exit(0);
		}
	cmdline[strlen(cmdline)-1] = '\0';
   for (;;)
	 {
   char *argv[2];
   argv [0] = "/bin/sh";
	 argv [1] = NULL;
   execvp(argv[0], argv);
   }

	}

	free(cmdline);
	return (0);

	

}
