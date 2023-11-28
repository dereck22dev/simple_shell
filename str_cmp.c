#include "shell.h"

/**
 * Compare two strings.
 * @param s1 The first string.
 * @param s2 The second string.
 * @return 0 if strings are equal, < 0 if s1 < s2, > 0 if s1 > s2.
 */
int str_cmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}
