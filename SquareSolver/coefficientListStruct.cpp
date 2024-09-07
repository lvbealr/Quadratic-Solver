#include <cstdio>
#include <cassert>
#include <cmath>

#include "coefficientListStruct.h"
#include "customAssert.h"

/*/ START OF COEFFICIENT STRUCT /*/
int coefficientListInitialize(coefficientList *coefficients) {
    customAssert(coefficients != NULL, 1);
    
    coefficients->a = NAN;
    coefficients->b = NAN;
    coefficients->c = NAN;

    return 0;
}

int coefficientListDestruct(coefficientList *coefficients) {
    customAssert(coefficients != NULL, 1);

    coefficients->a = NAN;
    coefficients->b = NAN;
    coefficients->c = NAN;

    return 0;
}
/*/ END OF COEFFICIENT STRUCT /*/