#ifndef SOLVER_H_
#define SOLVER_H_

#include "coefficientListStruct.h"

void linearSolver(coefficientList *coefficients, rootList *roots);
void squareSolver(coefficientList *coefficients, rootList *roots);
void solve(coefficientList *coefficients, rootList *roots);

#endif