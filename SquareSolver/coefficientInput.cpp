#include <cstdio>
#include <cmath>

#include "coefficientInput.h"
#include "stdinClean.h"
#include "coefficientListStruct.h"

bool coefficientInput(coefficientList *coefficients) {
    
    for (int tryNum = 0; tryNum < TRY_COUNT; tryNum++) {
        printf("Input values of coefficients a, b, c: ");
        
        if (scanf("%lg %lg %lg", &coefficients->a, &coefficients->b, &coefficients->c) != 3) {
            stdinClean();
        }
        else {
            return true;
        }
    }
    
    return false;
}