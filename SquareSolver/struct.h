#include <cstdio>
#include <cmath>
#include "solveCode.h"

#ifndef rootListStruct // TODO
#define rootListStruct

const int MAX_COUNT = 2;

struct rootList {
    int count = 0;
    double roots[MAX_COUNT] = {};
    solveCode status = INVALID;
};

void rootListInitialize(rootList *roots) {
    roots->count = 0;
    for (int index = 0; index < MAX_COUNT; index++) {
        roots->roots[index] = NAN;
    }
    roots->status = INVALID;
}

void rootListDestruct(rootList *roots) {
    roots->count = -1;
    for (int index = 0; index < MAX_COUNT; index++) {
        roots->roots[index] = NAN;
    }
    roots->status = INVALID;
}

int getRootCount(const rootList *roots) {
    switch (roots->status) {
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

bool pushRoot(rootList *roots, double root) {
    if ((roots->count < 0) && (roots->count >= getRootCount(roots))) {
        return false;
    }

    roots->roots[roots->count] = root;
    roots->count++;
    return true;
}

void printRoot(const rootList *roots) {
    int rootCount = getRootCount(roots);
    for (int index = 0; index < rootCount; index++) {
        printf("%lg\t", roots->roots[index]);
    }
}

void setStatus(rootList *roots, solveCode status) {
    roots->status = status;
}

#endif // rootListStruct
