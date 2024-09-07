#ifndef SOLVER_TEST_H_
#define SOLVER_TEST_H_
#include <cmath>

#include "rootListStruct.h"
#include "solver.h"

/*/ START OF TESTDATA STRUCT /*/
/**
 * @brief Struct That Contains Data To Test The Programm
 * 
 */
struct testData {
    double a             = NAN;
    double b             = NAN;
    double c             = NAN;
    double trueX1        = NAN;
    double trueX2        = NAN;
    solveCode trueStatus = INVALID;
};
/*/ END OF TESTDATA STRUCT /*/

/**
 * @brief Print Possible Error Message During Tests
 * 
 * @param [in] testNum 
 * @param [in] coefficient_a 
 * @param [in] coefficient_b 
 * @param [in] coefficient_c 
 * @param [in] trueX1 
 * @param [in] trueX2 
 * @param [in] trueStatus 
 * @param [in] testX1 
 * @param [in] testX2 
 * @param [in] testStatus 
 */
void printTestError(size_t testNum, double coefficient_a, double coefficient_b, double coefficient_c,
                    double trueX1, double trueX2, int trueStatus,
                    double testX1, double testX2, int testStatus);

/**
 * @brief Print Possible Message Of Success During Tests
 * 
 * @param [in] testNum 
 */
void printTestSuccess(size_t testNum);

/**
 * @brief Compare The Received Values With The Expected Ones 
 * 
 * @param [in] x 
 * @param [in] y 
 * @return bool Result Of Comparing The Components Of Test
 */
bool testCondition(double x, double y);

/**
 * @brief Solve Equation With Test Values
 * 
 * @param [in] test 
 * @param [in] testNum 
 */
void runTest(testData test, size_t testNum);

/**
 * @brief Run All Tests To Check The Programm
 * 
 */
void runAllTests();

#endif