#include "monty.h"

/**
 * main - entry point
 * @argc: number of args
 * @argv: list of arguments passed to our program
 * Return: no return
 */

int main(int argc, char **argv)
{
    FILE *fd;
    int line = 1;
    char *buffer = NULL, *str = NULL;
    size_t bufsize = 0;
    stack_t *stack;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    fd = fopen(argv[1], "r");
    if (fd == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&buffer, &bufsize, fd) > 0)
    {
        if (*buffer == '\n')
        {
            line++;
            continue;
        }
        str = strtok(buffer, " \t\n");
        if (str == NULL || *str == '#')
        {
            line++;
            continue;
        }
        global.arg = strtok(NULL, " \t\n");
        //monty(&stack, str, line);
        line++;
    }
    free(buffer);
    fclose(fd);
    exit(EXIT_SUCCESS);
}