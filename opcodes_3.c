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

/**
 * pchar - prints the char at the top of the stack
 * followed by a new line.
 * @stack: stack
 * @line: line number
 * Return: no return
 */

void pchar(stack_t **stack, unsigned int line)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
        exit(EXIT_FAILURE);
    }
    if (!((*stack)->n > 0 && (*stack)->n < 127))
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", (*stack)->n);
}

/**
 * pstr -  prints the string starting at the top of the stack
 * followed by a new line.
 * @stack: stack
 * @line: line number
 * Return: no return
 */

void pstr(stack_t **stack, unsigned int line)
{
    stack_t *curr = *stack;
    (void)line;
    if (*stack == NULL)
        printf("\n");

    while (curr != NULL && curr->n != 0 && isascii(curr->n))
    {
        printf("%c", curr->n);
        curr = curr->next;
    }
    printf("\n");
}