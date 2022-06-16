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

    if (global.mode == 0)
    {
        if (add_node_front(stack, atoi(n)) == NULL)
            exit(EXIT_FAILURE);
    }
    else if (global.mode == 1)
    {
        if (add_node_queue(stack, atoi(n)) == NULL)
            exit(EXIT_FAILURE);
    }
}


/**
 * pail - print the stack
 * @stack: stack given by function main
 * @line: line number
 * Return: no return
 */

void pall(stack_t **stack, unsigned int line)
{
    (void)line;
    print_stack(*stack);
}

