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

/**
 * nop - doesn't do anything
 * @stack: stack 
 * @line: line number
 * Return: no return
 */

void nop(stack_t **stack, unsigned int line)
{
    (void)stack;
    (void)line;
}

/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: stack 
 * @line: line number
 * Return: no return
 */

void sub(stack_t **stack, unsigned int line)
{
    int result = 0;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line);
        exit(EXIT_FAILURE);
    }
    result = (*stack)->next->n - (*stack)->n;
    pop(stack, line);
    (*stack)->n = result;
}

/**
 * div - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: stack 
 * @line: line number
 * Return: no return
 */

void div(stack_t **stack, unsigned int line)
{
    int result = 0;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line);
        exit(EXIT_FAILURE);
    }
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line);
        exit(EXIT_FAILURE);
    }
    
    result = (*stack)->next->n / (*stack)->n;
    pop(stack, line);
    (*stack)->n = result;
}
