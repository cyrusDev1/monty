#include "monty.h"

/**
 * monty - functions that run builtins
 * @stack: pointer to pointer to stack
 * @str: string to compare
 * @line: number of a line
 * Return: no return
 */

void monty(stack_t **stack, char *str, unsigned int line)
{
    instruction_t monty_funcs[] = OPCODES;
    int i = 0;

    if (!strcmp(str, "stack"))
    {
        global.mode = 1;
        return; 
    }else if (!strcmp(str, "queue"))
    {
        global.mode = 0;
        return; 
    }
    while (monty_funcs[i].opcode)
    {
        if (strcmp(monty_funcs[i].opcode, str) == 0)
        {
            monty_funcs[i].f(stack, line);
            return;
        }
        i++;
    }
    fprintf(stderr, "L%d: unknown instruction %s\n", line, str);
    exit(EXIT_FAILURE);
}
