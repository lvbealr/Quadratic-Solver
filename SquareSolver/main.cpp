// TODO DOXYGEN IN HEADERS
// TODO GOOGLE TESTS -VV parse args new module
// TODO flag --test (default manual), --VVtests
/**
 * @file coefficientInput.h
 * @author lvbealr
 * @brief Manual Entry Of Coefficients
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024 
 */

#include <cstdio>
#include <cassert>
#include <math.h>
#include <cctype>

#include "menu.h"
#include "coefficientInput.h"
#include "stdinClean.h"

int main() {
    char mode = {};

    printf("Choose mode: Test Mode (T) / Manual Mode (M). Input (T/M): ");
    mode = getchar();

    stdinClean();

    if (mode == 'T' || mode == 't') {
        testMode();
    }
    else if (mode == 'M' || mode == 'm') {
        manualMode();
    }
    else {
        printf("Wrong mode input!");
    }

    return 0;
}