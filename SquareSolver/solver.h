#ifndef SOLVER_H_
#define SOLVER_H_

#include "coefficientListStruct.h"

/**
 * @brief Activate Mode Of Solving Linear Equation
 * 
 * @param [in] coefficients 
 * @param [out] roots 
 */
void linearSolver(coefficientList *coefficients, rootList *roots);

/**
 * @brief Activate Mode Of Solving Quadratic Equation
 * 
 * @param [in] coefficients 
 * @param [out] roots 
 */
void squareSolver(coefficientList *coefficients, rootList *roots);

/**
 * @brief Activate Menu Of Choosing Solve Linear/Quadratic Equation
 * 
 * @param [in] coefficients 
 * @param [out] roots 
 */
void solve(coefficientList *coefficients, rootList *roots);

#endif