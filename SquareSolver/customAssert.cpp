#include <cstdio>

#include "customAssert.h"

bool customAssert(bool expression, assertionCode code, int line, const char *file, const char *function) {
    if (!expression) {
        printf("Assertion Error: line %d, file (%s), function (%s) \nError: %s", line, file, function, assertCodeString[code]);
        return false;   
    }
        return true;
    }
