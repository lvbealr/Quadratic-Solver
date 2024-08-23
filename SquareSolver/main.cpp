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