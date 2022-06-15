#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: stack given by function main
 * @line: line number
 * Return: no return
 */

void push(stack_t **stack, unsigned int line)
{
    char *n = global.arg;

    if (is_digit(n) == 0)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line);
        exit(EXIT_FAILURE);
    }
}