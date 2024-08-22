/**
 * @file main.cpp
 * @author lvbealr
 * @brief 
 * @version 1.0
 * @date 2024-08-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include <cstdio>
#include <cassert>
#include <math.h>
#include <cctype>

#include "menu.h"

int main() {
    char mode[1] = "";

    printf("Choose mode: Test Mode (0) / Manual Mode (1). Input (0/1):");
    scanf("%1s", mode);
    while (getchar() != '\n') {}

    if (*mode == '0') {
        testMode();
    }
    else if (*mode == '1') {
        manualMode();
    }
    else {
        printf("Wrong mode input!");
    }

    return 0;
}