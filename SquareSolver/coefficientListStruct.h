#ifndef COEFFICIENT_LIST_STRUCT_H_
#define COEFFICIENT_LIST_STRUCT_H_

#include <cmath>
/**
 * @brief Struct That Contains Coefficients A, B, C Of Quadratic Equation
 * 
 */
struct coefficientList {
    double a = NAN;
    double b = NAN;
    double c = NAN;
};

/*/ FUNCTION PROTOTYPES /*/
/**
 * @brief Initialize CoefficientList Struct
 * 
 * @param [out] coefficients 
 */
void coefficientListInitialize(coefficientList *coefficients);

/**
 * @brief Destruct CoefficientList Struct
 * 
 * @param [out] coefficients 
 */
void coefficientListDestruct(coefficientList *coefficients);
/*/ FUNCTION PROTOTYPES /*/
#endif