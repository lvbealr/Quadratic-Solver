#include "solverTest.h"
#include "zeroComparison.h"
#include "rootListStruct.h"
#include <math.h>
#include <cstdio>

static const char *solveCodeString[] = {
        "LINEAR_INF_ROOTS",
        "LINEAR_NO_ROOTS",
        "LINEAR_ONE_ROOT",
        "QUADRATIC_NO_ROOTS",
        "QUADRATIC_ONE_ROOT",
        "QUADRATIC_TWO_ROOTS",
        "INVALID"
};

/*/ START OF TESTS /*/
void printTestError(int testNum, double a, double b, double c,
                    double trueX1, double trueX2, int trueStatus,
                    double testX1, double testX2, int testStatus) {
    printf("\nTest %d: " "\033[1;31mFAILED! \033[0m"
                         "a = %lg, b = %lg, c = %lg\nx1 = %lg, x2 = %lg, testStatus = %s\n"
                         "EXPECTED:\nx1 = %lg, x2 = %lg, trueStatus = %s\n",
                         testNum, a, b, c, testX1, testX2, solveCodeString[testStatus],
                         trueX1, trueX2, solveCodeString[trueStatus]);
}

void printTestSuccess(int testNum) {
    printf("\nTest %d: " "\033[1;32mOK!\033[0m\n", testNum);
}

bool testCondition (double x, double y) {
    return (zeroComparison(x - y) == DOUBLE_EQUAL_EPS) || (isnan(x) && isnan(y));
}

void runTest(testData test, int testNum) {
    double testX1 = NAN, testX2 = NAN;
    rootList testRootList = {};
    rootListInitialize(&testRootList);

    solve(test.a, test.b, test.c, &testRootList);

    solveCode testStatus = testRootList.status;

    switch (testStatus) {
        case LINEAR_ONE_ROOT:
        case QUADRATIC_ONE_ROOT: {
            testX1 = testRootList.roots[0];
            break;
        }
        case QUADRATIC_TWO_ROOTS: {
            testX1 = testRootList.roots[0];
            testX2 = testRootList.roots[1];
            break;
        }
        case LINEAR_INF_ROOTS:
        case LINEAR_NO_ROOTS:
        case QUADRATIC_NO_ROOTS:
        case INVALID:
        default:
            break;
    }
    if (testCondition(testX1, test.trueX1) &&
        testCondition(testX2, test.trueX2) &&
        testStatus == test.trueStatus    ) {
        printTestSuccess(testNum);
    }
    else {
        printTestError(testNum, test.a, test.b, test.c, testX1,
                       testX2, test.trueStatus, test.trueX1, test.trueX2, testStatus);
    }
    rootListDestruct(&testRootList);
}

void runAllTests() {
    static testData tests[] = {
            {0,   0,   0,     NAN,       NAN,       LINEAR_INF_ROOTS},       // LINEAR_INF_ROOTS    --- OK
            {0,   0,   0,     1,         2,         LINEAR_INF_ROOTS},       // LINEAR_INF_ROOTS    --- FAILED
            {0,   0,   5,     NAN,       NAN,       LINEAR_NO_ROOTS},        // LINEAR_NO_ROOTS     --- OK
            {0,   0,   3,     .6,        NAN,       LINEAR_NO_ROOTS},        // LINEAR_NO_ROOTS     --- FAILED
            {0,   -.6, 3,     5,         NAN,       LINEAR_ONE_ROOT},        // LINEAR_ONE_ROOT     --- OK
            {0,   8,   3,     -9,        NAN,       LINEAR_ONE_ROOT},        // LINEAR_ONE_ROOT     --- FAILED
            {1,   2,   10,    NAN,       NAN,       QUADRATIC_NO_ROOTS},     // QUADRATIC_NO_ROOTS  --- OK
            {2.5, 999, 2,     3,         NAN,       QUADRATIC_NO_ROOTS},     // QUADRATIC_NO_ROOTS  --- FAILED
            {1,   -4,  4,     2,         NAN,       QUADRATIC_ONE_ROOT},     // QUADRATIC_ONE_ROOT  --- OK
            {1,   2,   1,     1,         NAN,       QUADRATIC_ONE_ROOT},     // QUADRATIC_ONE_ROOT  --- FAILED
            {2.5, 9.8, 3.4,   -3.535309, -0.384691, QUADRATIC_TWO_ROOTS},    // QUADRATIC_TWO_ROOTS --- OK
            {3,   7.4, -2.37, -2.75,     0.286901,  QUADRATIC_TWO_ROOTS}     // QUADRATIC_TWO_ROOTS --- FAILED
    };
    for (int testNum = 0; testNum < sizeof(tests)/sizeof(tests[0]); testNum++) {
        runTest(tests[testNum], testNum + 1);
    }
}
/*/ END OF TESTS /*/