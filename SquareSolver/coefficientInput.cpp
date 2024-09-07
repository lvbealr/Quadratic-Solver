#include <cstdio>
#include <cmath>

#include "coefficientInput.h"
#include "inOutStream.h"
#include "coefficientListStruct.h"
#include "customAssert.h"

int coefficientInput(coefficientList *coefficients) {
    customAssert(coefficients != NULL, 0);
    // TODO ASSERT rename
    for (int tryNum = 0; tryNum < TRY_COUNT; tryNum++) {
        printf("Input values of coefficients a, b, c: ");
        
        if (scanf("%lg %lg %lg", &coefficients->a, &coefficients->b, &coefficients->c) != 3) {
            stdinClean();
        }
        else {
            return 0;
        }
    }
    
    return 1;
}