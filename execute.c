#include "shell.h"

/**
 * execute_command - Executes a command entered by the user.
 * @input: The command to be executed.
 */
void execute_command(char *input)
{
    char *args[4]; 
    char *env[1];

    args[0] = NULL;
    args[1] = NULL;
    args[2] = NULL;
    args[3] = NULL;

    env[0] = NULL;

    if (input == NULL)
        return;

    if (str_cmp(input, "exit") == 0)
    {
        free(input);
        exit(EXIT_SUCCESS);
    }
    else if (str_cmp(input, "env") == 0)
    {
        display_environment();
    }
    else
    {
        if (access(input, F_OK | X_OK) == 0)
        {
            args[0] = input;
            exec_cmd(input, args, env);
        }
        else
        {
            char *path = getenv("PATH");
            char *token = str_tok(path, ":");

            while (token != NULL)
            {
                char full_path[MAX_INPUT_SIZE];

                str_format(full_path, MAX_INPUT_SIZE, "%s/%s", token, input);

                token = str_tok(NULL, ":");
            }

            printf("%s: command not found\n", input);
        }
    }
}
