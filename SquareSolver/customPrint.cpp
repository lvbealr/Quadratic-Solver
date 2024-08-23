#include <cstdio>
#include <cstdarg>

#include "customPrint.h"

void customPrint(textColor textColor, textAttribute textAttribute, backgroundColor backgroundColor, const char *format, ...) {
    va_list args;
    va_start(args, format);

    int d;
    double g;
    char c, *s;

    printf("\033[%d;%d;%dm", textAttribute, textColor, backgroundColor);
    vprintf(format, args);
    printf("\033[0m");

    va_end (args);
}   