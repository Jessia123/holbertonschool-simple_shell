#include "main.h"

/**
  * main - Main entry point for our program
  * @argc: Argument count to the main
  * @argv: Pointer to array of argument values
  *
  * Return: O Always success
  */

int main(int argc, char *argv[])
{
        (void)argc, (void)argv;
        write(STDOUT_FILENO, "MyShell$ ", 9);
        return (0);
}