#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: stack 
 * @line: line number
 * Return: no return
 */

void add(stack_t **stack, unsigned int line)
{
    int result = 0;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line);
        exit(EXIT_FAILURE);
    }
    result = (*stack)->n + (*stack)->next->n;
    pop(stack, line);
    (*stack)->n = result;
}