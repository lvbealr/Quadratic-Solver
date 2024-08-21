#ifndef SOLVER_TEST_H_
#define SOLVER_TEST_H_
#include <cmath>

#include "rootListStruct.h"
#include "solver.h"

/*/ START OF TESTDATA STRUCT /*/
struct testData {
    double a = NAN;
    double b = NAN;
    double c = NAN;
    double trueX1 = NAN;
    double trueX2 = NAN;
    solveCode trueStatus = INVALID;
};
/*/ END OF TESTDATA STRUCT /*/

void printTestError(int, double, double, double, double, double, int, double, double, int);
void printTestSuccess(int);
bool testCondition(double, double);
void runTest(testData, int);
void runAllTests();

#endif