#ifndef GOOGLE_TESTS_H_
#define GOOGLE_TESTS_H_

#include "rootListStruct.h"

/**
 * @brief Run Google Tests
 * @return int Success/Failure Return Code [0/1] 
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
 * @return int Success/Failure Return Code [0/1] 
 */
int runGoogleTest(rootList *receivedValues, double *testX1, double *testX2,
                solveCode *receivedStatus, int testNum);

#endif