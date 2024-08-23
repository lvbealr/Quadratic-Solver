#ifndef COEFFICIENT_LIST_STRUCT_H_
#define COEFFICIENT_LIST_STRUCT_H_

#include <cmath>

struct coefficientList {
    double a = NAN;
    double b = NAN;
    double c = NAN;
};

/*/ FUNCTION PROTOTYPES /*/
void coefficientListInitialize(coefficientList *coefficients);
void coefficientListDestruct(coefficientList *coefficients);
/*/ FUNCTION PROTOTYPES /*/
#endif