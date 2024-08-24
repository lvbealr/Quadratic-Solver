#ifndef GOOGLE_TESTS_H_
#define GOOGLE_TESTS_H_

#include "rootListStruct.h"

/**
 * @brief Run Google Tests
 * 
 */
int runAllGoogleTests(int argc, char *argv[]);

/**
 * @brief Solve By Google Test
 * 
 * @param [out] receivedValues 
 * @param [out] testX1 
 * @param [out] testX2 
 * @param [out] receivedStatus 
 * @param [in] testNum 
 */
void runGoogleTest(rootList *receivedValues, double *testX1, double *testX2,
                solveCode *receivedStatus, int testNum);


/// @brief Number Of Completed Google Tests
static int googleTestNum = 0;

#endif