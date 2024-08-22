#ifndef SOLVER_H_
#define SOLVER_H_

void linearSolver(double coefficient_b, double coefficient_c, rootList *roots);
void squareSolver(double coefficient_a, double coefficient_b, double coefficient_c, rootList *roots);
void solve(double coefficient_a, double coefficient_b, double coefficient_c, rootList *roots);

#endif