#include "shell.h"

char *str_tok(char *str, const char *delim)
{
    static char *current_str = NULL;
    char *token_start;
    char *token_end; 

    if (str != NULL)
        current_str = str;
    if (current_str == NULL)
        return NULL;

    token_end = str_pbrk(current_str, delim);
    if (token_end != NULL)
    {
        *token_end = '\0';
        token_start = current_str;
        current_str = token_end + 1;
    }
    else
    {
        token_start = current_str;
        current_str = NULL;
    }

    return token_start;
}
