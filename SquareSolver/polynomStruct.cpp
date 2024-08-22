#include <cstdio>
#include <cassert>
#include <cmath>

#include "polynomStruct.h"

void polynomInitialize(polynom *polynom, int maxRootCount, double a, double b, double c) {
    assert(polynom != NULL);

    polynom->a = a;
    polynom->b = b;
    polynom->c = c;
    polynom->maxRootCount = maxRootCount;
    polynom->count = 0;
    for (int index = 0; index < polynom->maxRootCount; index++) {
        polynom->roots[index] = INFINITY;
    }
    polynom->status = INVALID;
}

void polynomDestruct(polynom *polynom) {
    assert(polynom != NULL);
    
    polynom->a = NAN;
    polynom->b = NAN;
    polynom->c = NAN;
    polynom->maxRootCount = 2147483647;
    polynom->count = INVALID_COUNT;
    for (int index = 0; index < polynom->maxRootCount; index++) {
        polynom->roots[index] = INFINITY;
    }
    polynom->status = INVALID;
}

int getRootCount(const polynom *polynom) {
    assert(polynom != NULL);

    switch (polynom->status) {
        case LINEAR_ONE_ROOT:
        case QUADRATIC_ONE_ROOT:
            return 1;
        case QUADRATIC_TWO_ROOTS:
            return 2;
        case LINEAR_NO_ROOTS:
        case QUADRATIC_NO_ROOTS:
        case LINEAR_INF_ROOTS:
        case INVALID:
        default:
            return 0;
    }
}

bool pushRoot(polynom *polynom, double root) {
    assert(polynom != NULL);

    if ((polynom->count < 0) && (polynom->count >= getRootCount(polynom))) {
        return false;
    }
    polynom->roots[polynom->count] = root;
    polynom->count++;
    return true;
}

void printRoot(const polynom *polynom) {
    assert(polynom != NULL);

    int rootCount = getRootCount(polynom);
    for (int index = 0; index < rootCount; index++) {
        printf("%lg\t", polynom->roots[index]);
    }
}

void setStatus(polynom *polynom, solveCode status) {
    assert(polynom != NULL);

    polynom->status = status;
}

void printResult(polynom *polynom) {
    assert(polynom != NULL);

    switch (polynom->status) {
        case LINEAR_INF_ROOTS: {
            printf("Infinitely many solutions");
            break;
        }
        case LINEAR_NO_ROOTS: {
            printf("No solutions");
            break;
        }
        case LINEAR_ONE_ROOT: {
            printf("It is linear (non-quadratic) "
                   "equation\nSolutions: ");
            break;
        }
        case QUADRATIC_NO_ROOTS: {
            printf("D < 0: No real solutions");
            break;
        }
        case QUADRATIC_ONE_ROOT: {
            printf("D = 0\nSolutions: ");
            break;
        }
        case QUADRATIC_TWO_ROOTS: {
            printf("D > 0\nSolutions: ");
            break;
        }
        case INVALID:
        default:
            break;
    }
    printRoot(polynom);
    printf("\n");
}