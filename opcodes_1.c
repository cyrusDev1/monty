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

    if (global.mode == STACK)
    {
        if (add_node_front(stack, atoi(n)) == NULL)
            exit(EXIT_FAILURE);
    }
    else if (global.mode == QUEUE)
    {
        if (add_node_queue(stack, atoi(n)) == NULL)
            exit(EXIT_FAILURE);
    }
}

/**
 * pall - print the stack
 * @stack: stack given by function main
 * @line: line number
 * Return: no return
 */

void pall(stack_t **stack, unsigned int line)
{
    (void)line;
    print_stack(*stack);
}

/**
 * pint - prints the value at the top of the stack
 * followed by a new line
 * @stack: stack given by function main
 * @line: line number
 * Return: no return
 */

void pint(stack_t **stack, unsigned int line)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

/**
 * pop -  removes the top element of the stack
 * @stack: stack given by function main
 * @line: line number
 * Return: no return
 */

void pop(stack_t **stack, unsigned int line)
{
    stack_t *tmp = NULL;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line);
        exit(EXIT_FAILURE);
    }

    tmp = (*stack)->next;
    free(*stack);
    *stack = tmp;
    if (*stack == NULL)
        return;
    (*stack)->prev = NULL;
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: stack given by function main
 * @line: line number
 * Return: no return
 */

void swap(stack_t **stack, unsigned int line)
{
    stack_t *tmp = NULL;
    int tmp_arg = 0;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line);
        exit(EXIT_FAILURE);
    }

    tmp = *stack;
    tmp_arg = tmp->n;
    tmp->n = tmp_arg;

    tmp->n = tmp->next->n;
    tmp->next->n = tmp_arg;
}
