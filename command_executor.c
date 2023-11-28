#include "shell.h"

/**
 * exec_cmd - Executes a command with arguments and environment.
 * @command: The full path to the command.
 * @args: An array of strings representing the command and its arguments.
 * @env: An array of strings representing the environment.
 * 
 * Returns: On success, it does not return. On failure, -1 is returned.
 */
int exec_cmd(const char *command, char *const args[], char *const env[])
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if (pid == 0)
    {
        if (execve(command, args, env) == -1)
        {
            perror(command);
            _exit(EXIT_FAILURE);
        }
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
        {
            return -1;
        }
    }

    return 0;
}

