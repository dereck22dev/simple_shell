#include "shell.h"

/**
 * Format a string with %s, %d, %c, %f, and %x specifiers.
 * @param str The buffer to store the formatted string.
 * @param size The size of the buffer.
 * @param format The format string.
 * @param args Additional arguments to be formatted.
 * @return The number of characters written (excluding null byte).
 */
int str_format(char *str, size_t size, const char *format, void *args) {
    size_t written = 0;
    const char *src = format;
    char *dest = str;

    size_t i = 0;
    char *s;
    int d;
    char c;
    double f;
    unsigned int x;

    int frac;

    for (src = format; *src != '\0' && written < size - 1; src++) {
        if (*src == '%' && *(src + 1) != '\0') {
            src++;

            switch (*src) {
                case 's':
                    s = (char *)args;
                    while (*s != '\0' && written < size - 1) {
                        *dest++ = *s++;
                        written++;
                    }
                    break;
                case 'd':
                    d = *((int *)args);
                    while (d != 0 && written < size - 1) {
                        *dest++ = '0' + d % 10;
                        d /= 10;
                        written++;
                    }
                    break;
                case 'c':
                    c = *((int *)args);
                    *dest++ = c;
                    written++;
                    break;
                case 'f':
                    f = *((double *)args);
                    d = (int)f;
                    while (d != 0 && written < size - 1) {
                        *dest++ = '0' + d % 10;
                        d /= 10;
                        written++;
                    }

                    if (written < size - 1) {
                        *dest++ = '.';
                        written++;
                    }
                    frac = (int)((f - (int)f) * 1000000);
                    while (frac != 0 && written < size - 1) {
                        *dest++ = '0' + frac % 10;
                        frac /= 10;
                        written++;
                    }
                    break;
                case 'x':
                    x = *((unsigned int *)args);
                    while (x != 0 && written < size - 1) {
                        *dest++ = "0123456789abcdef"[x % 16];
                        x /= 16;
                        written++;
                    }
                    break;
                default:
                    break;
            }

            i++;
        } else {
            *dest++ = *src;
            written++;
        }
    }

    *dest = '\0';

    return written;
}