#include <cassert>
#include <math.h>

#include "zeroComparison.h"
#include "rootListStruct.h"

void linearSolver(const double b, const double c, rootList *roots) {
    assert(roots != NULL);
    
    if (zeroComparison(b) == DOUBLE_EQUAL_EPS) {
        if (zeroComparison(c) == DOUBLE_EQUAL_EPS) {
            setStatus(roots, LINEAR_INF_ROOTS);
        }
        else {
            setStatus(roots, LINEAR_NO_ROOTS);
        }
    }
    else {
        setStatus(roots, LINEAR_ONE_ROOT);
        pushRoot(roots, -c/b);
    }
}

void squareSolver(const double a, const double b,
                  const double c, rootList *roots) {
    assert(roots != NULL);

    double const discriminant = b*b - 4*a*c;

    zeroComparisonCode code = zeroComparison(discriminant);
    switch (code) {
        case DOUBLE_LESS_EPS: {
            setStatus(roots, QUADRATIC_NO_ROOTS);
            break;
        }
        case DOUBLE_EQUAL_EPS: {
            setStatus(roots, QUADRATIC_ONE_ROOT);
            pushRoot(roots, -b / 2 / a);
            break;
        }
        case DOUBLE_GREATER_EPS: {
            setStatus(roots, QUADRATIC_TWO_ROOTS);

            double p = -b / 2 / a;
            double q = sqrt(discriminant) / 2 / a;

            pushRoot(roots, (p - q));
            pushRoot(roots, (p + q));
            break;
        }
        default:
            break;
    }
}

void solve(const double a, const double b,
           const double c, rootList *roots) {

    assert(roots != NULL);

    if (zeroComparison(a) == DOUBLE_EQUAL_EPS) {
        linearSolver(b, c, roots);
    }
    else {
        squareSolver(a, b, c, roots);
    }
}