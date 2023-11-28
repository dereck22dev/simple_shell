#include "shell.h"
#include <stddef.h>

/**
 * Find the first character in str that is in the delim set.
 * @param str The string to search.
 * @param delim The set of characters to search for.
 * @return A pointer to the first matching character, or NULL if not found.
 */
char *str_pbrk(const char *str, const char *delim) {
    while (*str != '\0') {
        const char *d = delim;
        while (*d != '\0') {
            if (*str == *d) {
                return (char *)str;
            }
            ++d;
        }
        ++str;
    }
    return NULL;
}
