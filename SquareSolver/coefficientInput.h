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
 * @return true 
 * @return false 
 */
bool coefficientInput(coefficientList *coefficients);

#endif