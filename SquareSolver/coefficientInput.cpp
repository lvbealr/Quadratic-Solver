#include <cstdio>
#include <cmath>

#include "coefficientInput.h"

bool coefficientInput(double *a, double *b, double *c) {
    
    for (int tryNum = 0; tryNum < TRY_COUNT; tryNum++) {
        printf("Input values of coefficients a, b, c: ");
        
        if (scanf("%lg %lg %lg", a, b, c) != 3) {
            while (getchar() != '\n') {}
        }
        else {
            return true;
        }
    }

    return false;
}