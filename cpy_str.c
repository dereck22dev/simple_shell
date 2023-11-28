#include "shell.h"

char *cpy_str(char *dest, const char *src)
{
    char *original_dest = dest;
    
    if (dest == NULL || src == NULL) {
        return NULL;
    }

    while ((*dest++ = *src++) != '\0') {
        if (dest - original_dest >= BUFSIZ) {
            return NULL;
        }
    }

    return original_dest;
}

