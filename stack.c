#include "monty.h"

/**
 * add_node-front - adds node to the start of a stack (front)
 * @stack: stack
 * @n: number for new node
 * Return: null or new node
 */

stack_t *add_node_front(stack_t **stack, const int n)
{
    stack_t *new = malloc(sizeof(stack_t));

    if (new == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free(new);
        return (NULL);
    }

    new->n = n;
    new->next = *stack;
    new->prev = NULL;
    if(*stack != NULL)
        (*stack)->prev = new;
    *stack = new;
    return (new);
}

/**
 * add_node-queue - adds node to the start of a stack (queue)
 * @stack: stack
 * @n: number for new node
 * Return: null or new node
 */

stack_t *add_node_queue(stack_t **stack, const int n)
{
    stack_t *new = malloc(sizeof(stack_t));
    stack_t *curr = *stack;

    if (new == NULL)
    {
        free(new);
        return (NULL);
    }
    new->n = n;
    if (*stack == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        *stack = new;
        return (new);
    }
    while (curr != NULL)
    {
        if (curr->next == NULL)
        {
            new->next = NULL;
            new->prev = curr;
            curr->next = new;
            break;
        }
        curr = curr->next;
    }
    return (new);
}

/**
 * print_stack - prints the stack
 * @stack: pointer to head stack
 * Return: size of stack
 */

size_t print_stack(const stack_t *stack)
{
    size_t i = 0;
    while (stack != NULL)
    {
        printf("%d\n", stack->n);
        stack = stack->next;
        i++;
    }
    return (i);
}

/**
 * free-stack - frees a stack
 * @stack: pointer to stack
 * Return: no return
 */

void free_stack(stack_t *stack)
{
    stack_t *curr = stack;
    stack_t *next;

    if (stack != NULL)
    {
        next = stack->next;
        while (curr)
        {
            free(curr);
            curr = next;
            if (next != NULL)
                next = next->next;
        }  
    }
}