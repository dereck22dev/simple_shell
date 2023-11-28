#include "shell.h"

extern char **environ;

/**
 * display_environment - Displays the environment variables.
 */
void display_environment(void)
{
    char **env = environ;
    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}

