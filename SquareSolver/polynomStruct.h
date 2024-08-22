#ifndef POLYNOM_STRUCT_H_
#define POLYNOM_STRUCT_H_

#include <cmath>

const int INVALID_COUNT = -1;

enum solveCode {
    LINEAR_INF_ROOTS    = 0, // a, b, c = 0
    LINEAR_NO_ROOTS     = 1, // a, b = 0; c != 0
    LINEAR_ONE_ROOT     = 2, // a = 0; b != 0
    QUADRATIC_NO_ROOTS  = 3, // D < 0
    QUADRATIC_ONE_ROOT  = 4, // D = 0
    QUADRATIC_TWO_ROOTS = 5, // D > 0
    INVALID             = 6
};

/*/ POLYNOM STRUCT /*/
struct polynom {
    double a = NAN;
    double b = NAN;
    double c = NAN;
    int maxRootCount = 0;
    int count = 0;
    double *roots = (double *)calloc(maxRootCount, sizeof(double));
    solveCode status = INVALID;
};
/*/ POLYNOM STRUCT /*/

/*/ FUNCTION PROTOTYPES /*/
void polynomInitialize(polynom *polynom, int maxRootCount, double a, double b, double c);
void polynomDestruct(polynom *polynom);
int getRootCount(const polynom *polynom);
bool pushRoot(polynom *polynom, double root);
void printRoot(const polynom *polynom);
void setStatus(polynom *polynom, solveCode statusCode);
void printRestuls(polynom *polynom);
/*/ FUNCTION PROTOTYPES /*/
#endif