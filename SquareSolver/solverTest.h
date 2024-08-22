#ifndef SOLVER_TEST_H_
#define SOLVER_TEST_H_
#include <cmath>

#include "rootListStruct.h"
#include "solver.h"

/*/ START OF TESTDATA STRUCT /*/
struct testData {
    double a             = NAN;
    double b             = NAN;
    double c             = NAN;
    double trueX1        = NAN;
    double trueX2        = NAN;
    solveCode trueStatus = INVALID;
};
/*/ END OF TESTDATA STRUCT /*/

void printTestError(int testNum, double coefficient_a, double coefficient_b, double coefficient_c,
                    double trueX1, double trueX2, int trueStatus,
                    double testX1, double testX2, int testStatus);
void printTestSuccess(int testNum);
bool testCondition(double x, double y);
void runTest(testData test, int testNum);
void runAllTests();

#endif