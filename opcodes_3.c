#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: stack 
 * @line: line number
 * Return: no return
 */

void mod(stack_t **stack, unsigned int line)
{
    int result = 0;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line);
        exit(EXIT_FAILURE);
    }

    result = (*stack)->next->n % (*stack)->n;
    pop(stack, line);
    (*stack)->n = result;
}
