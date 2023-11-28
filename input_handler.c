#include "shell.h"

/**
 * remove_newline - Removes the newline character from a string.
 * @str: The string to modify.
 */
void remove_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

/**
 * read_input_handler - Reads a line of input from the user.
 *
 * Return: A pointer to the input string.
 */
char *read_input_handler(void)
{
    char *input = NULL;
    size_t len = 0;

    if (getline(&input, &len, stdin) == -1)
    {
        free(input);
        return NULL;
    }

    remove_newline(input);

    return input;
}

/**
 * r_input - Reads a line of input from the user.
 *
 * Return: A pointer to the input string.
 */
char *r_input(void)
{
    char *input = NULL;
    size_t size = 0;

    if (getline(&input, &size, stdin) == -1)
    {
        free(input);
        return NULL;
    }

    input[str_cmp(input, "\n")] = '\0';

    return input;
}
