#include "shell.h"

extern char **environ;


/**
 * display_prompt - Displays the shell prompt.
 */
void display_prompt(void)
{
    printf("#cisfun$ ");
    fflush(stdout);
}

/**
 * read_input - Reads a line of input from the user.
 *
 * Return: A pointer to the input string.
 */
char *read_input(void)
{
    char *input = NULL;
    size_t len = 0;

    if (getline(&input, &len, stdin) == -1)
    {
        free(input);
        return NULL;
    }

    input[strcspn(input, "\n")] = '\0';

    return input;
}

/**
 * execute_command - Executes a command entered by the user.
 * @input: The command to be executed.
 */
void execute_command(char *input)
{

    int i;
    
    if (strcmp(input, "exit") == 0)
    {
        free(input);
        exit(EXIT_SUCCESS);
    }
    else if (strcmp(input, "env") == 0)
    {
        char **env = environ;
        while (*env != NULL)
        {
            printf("%s\n", *env);
            env++;
        }
    }
    else
    {
        char *path = "/bin/";
        char full_path[MAX_INPUT_SIZE];
        strcpy(full_path, path);
        strcat(full_path, input);

        if (access(full_path, F_OK) == 0)
        {
            pid_t pid = fork();

            if (pid == -1)
            {
                perror("fork");
            }
            else if (pid == 0)
            {
                char *args[MAX_INPUT_SIZE];
                args[0] = strtok(input, " ");

                i = 1;
                while ((args[i] = strtok(NULL, " ")) != NULL)
                {
                    i++;
                }

                if (execve(full_path, args, environ) == -1)
                {
                    perror(args[0]);
                    _exit(EXIT_FAILURE);
                }
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
        else
        {
            printf("%s: command not found\n", input);
        }
    }
}

