#include "monty.h"

/**
 * is_digit - check if arg is digit and is not null
 * @string: arg to checked
 * Return: 0 or 1
 */

int is_digit(char *string)
{
    if (string == NULL || *string == '\0')
        return (0);
    if (*string == '-')
        string++;
    while (*string)
    {
        if (isdigit(*string) == 0)
            return (0);
        string++;
    }
    return (1); 
}