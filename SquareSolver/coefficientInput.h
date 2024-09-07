#ifndef COEFFICIENT_INPUT_H_
#define COEFFICIENT_INPUT_H_
#include <cmath>

#include "coefficientListStruct.h"

/**
 * @brief Max Number Of Coefficients Input Tries
 * 
 */
const int TRY_COUNT = 3;

/**
 * @brief Check Status Of Input Coefficients
 * 
 * @param [out] coefficients 
 * @return int Success/Failure Return Code [0/1] 
 */
int coefficientInput(coefficientList *coefficients);

#endif