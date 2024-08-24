#include <math.h>
#include <cstdio>

#include "solverTest.h"
#include "zeroComparison.h"
#include "rootListStruct.h"
#include "customPrint.h"
#include "testData.h"

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
    printf("\nTest %3d: ", testNum);
    customPrint(red, bold, bgDefault, "%-8s", "[ERROR] ");
    printf("a = %-6lg b = %-6lg c = %-6lg\nx1 = %-6.5lg\tx2 = %-6.5lg\ttestStatus = %d\n", 
            a, b, c, testX1, testX2, testStatus);
    customPrint(yellow, bold, bgDefault, "%s", "EXPECTED:\n");
    printf("x1 = %-6.5lg\tx2 = %-6.5lg\ttrueStatus = %d\n", trueX1, trueX2, trueStatus);
}

void printTestSuccess(int testNum) {
    printf("\nTest %3d: ", testNum);
    customPrint(green, bold, bgDefault, "%-8s", "[SUCCESS]\n");
}

bool testCondition (double x, double y) {
    return (zeroComparison(x - y) == DOUBLE_EQUAL_EPS) || (isnan(x) && isnan(y));
}

void runTest(testData test, int testNum) {
    double testX1 = NAN, testX2 = NAN;

    rootList testRootList = {};
    rootListInitialize(&testRootList);

    coefficientList coefficients = {};
    coefficientListInitialize(&coefficients);
    
    coefficients.a = test.a;
    coefficients.b = test.b;
    coefficients.c = test.c;

    solve(&coefficients, &testRootList); 

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

    for (int testNum = 0; testNum < sizeof(tests)/sizeof(tests[0]); testNum++) {
        runTest(tests[testNum], testNum + 1);
    }
}
/*/ END OF TESTS /*/