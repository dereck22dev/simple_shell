#include "shell.h"

/**
 * execute_external_command - Executes an external command.
 * @input: The command to be executed.
 */
void execute_external_command(char *input)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
    }
    else if (pid == 0)
    {
        char *path = getenv("PATH");
        char *token = str_tok(path, ":");

        char **args = NULL;
        char *env[] = {NULL};

        while (token != NULL)
        {
            char full_path[MAX_INPUT_SIZE];
            snprintf(full_path, sizeof(full_path), "%s/%s", token, input);
            printf("Full path: %s\n", full_path);

            if (access(full_path, F_OK | X_OK) == 0)
            {
                args = malloc(2 * sizeof(char *));
                if (args == NULL)
                {
                    perror("malloc");
                    _exit(EXIT_FAILURE);
                }
                args[0] = input;
                args[1] = NULL;

                if (exec_cmd(full_path, args, env) == -1)
                {
                    perror(full_path);
                    free(args);
                    _exit(EXIT_FAILURE);
                }
            }

            token = strtok(NULL, ":");
        }

        printf("%s: command not found\n", input);
        free(args);
        _exit(EXIT_FAILURE);
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
        {
            printf("%s: command not found\n", input);
        }
    }
}
