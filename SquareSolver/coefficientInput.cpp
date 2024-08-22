#include <cstdio>
#include <cmath>

#include "coefficientInput.h"
#include "stdinClean.h"

bool coefficientInput(double *a, double *b, double *c) {
    
    for (int tryNum = 0; tryNum < TRY_COUNT; tryNum++) {
        printf("Input values of coefficients a, b, c: ");
        
        if (scanf("%lg %lg %lg", a, b, c) != 3) {
            stdinClean();
        }
        else {
            return true;
        }
    }

    // getchar() EOF
    // int currentSymbol;
    // currentSymbol = getchar();
    // while (currentSymbol != '\n' || currentSymbol != EOF)
    // TOOD isspace()
    
    return false;
}