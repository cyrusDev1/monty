#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define OPCODES {\
{"push", push},\
{"pall", pall},\
{"pint", pint},\
{"pop", pop},\
{"swap", swap},\
{"add", add},\
{NULL, NULL}}

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct global_c - argument for the current opcode
* @mode: stack mode, stack (default) and queue
* @arg: the arguments of the string
*
* Description: global structure used to pass data around the functions easily
*/

typedef struct global_c
{
    int mode;
    char *arg;
} global_c;
global_c global;

void monty(stack_t **stack, char *str, unsigned int line);

void push(stack_t **stack, unsigned int line);
void pall(stack_t **stack, unsigned int line);
void pint(stack_t **stack, unsigned int line);
void pop(stack_t **stack, unsigned int line);
void swap(stack_t **stack, unsigned int line);
void add(stack_t **stack, unsigned int line);


int is_digit(char *string);

stack_t *add_node_front(stack_t **stack, const int n);
stack_t *add_node_queue(stack_t **stack, const int n);
size_t print_stack(const stack_t *stack);
void free_stack(stack_t *stack);

#endif