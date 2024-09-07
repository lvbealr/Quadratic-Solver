#include <cstdio>
#include <cassert>
#include <cmath>

#include "rootListStruct.h"
#include "customAssert.h"

/*/ START OF ROOTLIST STRUCT /*/
int rootListInitialize(rootList *roots) {
    customAssert(roots != NULL, 1);

    roots->count = 0;
    for (int index = 0; index < MAX_ROOT_COUNT; index++) {
        roots->roots[index] = INFINITY;
    }
    roots->status = INVALID;
    return 0;
}

int rootListDestruct(rootList *roots) {
    customAssert(roots != NULL, 1);

    roots->count = INVALID_COUNT;
    for (int index = 0; index < MAX_ROOT_COUNT; index++) {
        roots->roots[index] = INFINITY;
    }
    roots->status = INVALID;
    return 0;
}

int getRootCount(const rootList *roots) {
    customAssert(roots != NULL, 1);

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

int pushRoot(rootList *roots, double root) {
    customAssert(roots != NULL, 1);

    if ((roots->count < 0) && (roots->count >= getRootCount(roots))) {
        return false;
    }

    roots->roots[roots->count] = root;
    roots->count++;
    return true;
}

int printRoot(const rootList *roots) {
    customAssert(roots != NULL, 1);

    int rootCount = getRootCount(roots);
    for (int index = 0; index < rootCount; index++) {
        printf("%lg\t", roots->roots[index]);
    }

    return 0;
}

int setStatus(rootList *roots, solveCode status) {
    customAssert(roots != NULL, 1);

    roots->status = status;

    return 0;
}

int printResult(rootList *roots) {
    customAssert(roots != NULL, 1);
    
    switch (roots->status) {
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
    printRoot(roots);
    printf("\n");

    return 0;
}
/*/ END OF ROOTLIST STRUCT /*/