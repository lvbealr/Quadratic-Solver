#include <cmath>
#include <gtest/gtest.h>

#include "googleTests.h"
#include "solverTest.h"
#include "testData.h"
#include "rootListStruct.h"
#include "solver.h"

void runGoogleTest(rootList *receivedValues, double *testX1, double *testX2,
                solveCode *receivedStatus, int testNum) {

    coefficientList testCoefficients = {};
    coefficientListInitialize(&testCoefficients);

    testCoefficients.a = tests[testNum].a;
    testCoefficients.b = tests[testNum].b;
    testCoefficients.c = tests[testNum].c;

    solve(&testCoefficients, receivedValues);

    *receivedStatus = receivedValues->status;

    switch (*receivedStatus) {
        case LINEAR_ONE_ROOT:
        case QUADRATIC_ONE_ROOT: {
            *testX1 = receivedValues->roots[0];
            break;
        }
        case QUADRATIC_TWO_ROOTS: {
            *testX1 = receivedValues->roots[0];
            *testX2 = receivedValues->roots[1];
            break;
        }
        case LINEAR_INF_ROOTS:
        case LINEAR_NO_ROOTS:
        case QUADRATIC_NO_ROOTS:
        case INVALID:
        default:
            break;
    }
}

TEST(QUADRATIC_EQUATION, ALL_NULLS_SUCCESS) {
    double testX1 = NAN, testX2 = NAN;
    solveCode receivedStatus = INVALID;

    rootList receivedValues = {};
    rootListInitialize(&receivedValues);

    runGoogleTest(&receivedValues, &testX1, &testX2, &receivedStatus, googleTestNum);

    EXPECT_TRUE(testCondition(testX1, tests[googleTestNum].trueX1));
    EXPECT_TRUE(testCondition(testX2, tests[googleTestNum].trueX2));
    EXPECT_TRUE(testCondition(receivedStatus, tests[googleTestNum].trueStatus));
    googleTestNum++;
}

TEST(QUADRATIC_EQUATION, ALL_NULLS_FAIL) {
    double testX1 = NAN, testX2 = NAN;
    solveCode receivedStatus = INVALID;

    rootList receivedValues = {};
    rootListInitialize(&receivedValues);

    runGoogleTest(&receivedValues, &testX1, &testX2, &receivedStatus, googleTestNum);

    EXPECT_TRUE(testCondition(testX1, tests[googleTestNum].trueX1));
    EXPECT_TRUE(testCondition(testX2, tests[googleTestNum].trueX2));
    EXPECT_TRUE(testCondition(receivedStatus, tests[googleTestNum].trueStatus));
    googleTestNum++;
}


TEST(QUADRATIC_EQUATION, ALL_NULLS_EXCEPT_C_SUCCESS) {
    double testX1 = NAN, testX2 = NAN;
    solveCode receivedStatus = INVALID;

    rootList receivedValues = {};
    rootListInitialize(&receivedValues);

    runGoogleTest(&receivedValues, &testX1, &testX2, &receivedStatus, googleTestNum);

    EXPECT_TRUE(testCondition(testX1, tests[googleTestNum].trueX1));
    EXPECT_TRUE(testCondition(testX2, tests[googleTestNum].trueX2));
    EXPECT_TRUE(testCondition(receivedStatus, tests[googleTestNum].trueStatus));
    googleTestNum++;
}

TEST(QUADRATIC_EQUATION, ALL_NULLS_EXCEPT_C_FAIL) {
    double testX1 = NAN, testX2 = NAN;
    solveCode receivedStatus = INVALID;

    rootList receivedValues = {};
    rootListInitialize(&receivedValues);

    runGoogleTest(&receivedValues, &testX1, &testX2, &receivedStatus, googleTestNum);

    EXPECT_TRUE(testCondition(testX1, tests[googleTestNum].trueX1));
    EXPECT_TRUE(testCondition(testX2, tests[googleTestNum].trueX2));
    EXPECT_TRUE(testCondition(receivedStatus, tests[googleTestNum].trueStatus));
    googleTestNum++;
}

TEST(QUADRATIC_EQUATION, A_IS_NULL_SUCCESS) {
    double testX1 = NAN, testX2 = NAN;
    solveCode receivedStatus = INVALID;

    rootList receivedValues = {};
    rootListInitialize(&receivedValues);

    runGoogleTest(&receivedValues, &testX1, &testX2, &receivedStatus, googleTestNum);

    EXPECT_TRUE(testCondition(testX1, tests[googleTestNum].trueX1));
    EXPECT_TRUE(testCondition(testX2, tests[googleTestNum].trueX2));
    EXPECT_TRUE(testCondition(receivedStatus, tests[googleTestNum].trueStatus));
    googleTestNum++;
}

TEST(QUADRATIC_EQUATION, A_IS_NULL_FAIL) {
    double testX1 = NAN, testX2 = NAN;
    solveCode receivedStatus = INVALID;

    rootList receivedValues = {};
    rootListInitialize(&receivedValues);

    runGoogleTest(&receivedValues, &testX1, &testX2, &receivedStatus, googleTestNum);

    EXPECT_TRUE(testCondition(testX1, tests[googleTestNum].trueX1));
    EXPECT_TRUE(testCondition(testX2, tests[googleTestNum].trueX2));
    EXPECT_TRUE(testCondition(receivedStatus, tests[googleTestNum].trueStatus));
    googleTestNum++;
}

TEST(QUADRATIC_EQUATION, D_LESS_NULL_SUCCESS) {
    double testX1 = NAN, testX2 = NAN;
    solveCode receivedStatus = INVALID;

    rootList receivedValues = {};
    rootListInitialize(&receivedValues);

    runGoogleTest(&receivedValues, &testX1, &testX2, &receivedStatus, googleTestNum);

    EXPECT_TRUE(testCondition(testX1, tests[googleTestNum].trueX1));
    EXPECT_TRUE(testCondition(testX2, tests[googleTestNum].trueX2));
    EXPECT_TRUE(testCondition(receivedStatus, tests[googleTestNum].trueStatus));
    googleTestNum++;
}

TEST(QUADRATIC_EQUATION, D_LESS_NULL_FAIL) {
    double testX1 = NAN, testX2 = NAN;
    solveCode receivedStatus = INVALID;

    rootList receivedValues = {};
    rootListInitialize(&receivedValues);

    runGoogleTest(&receivedValues, &testX1, &testX2, &receivedStatus, googleTestNum);

    EXPECT_TRUE(testCondition(testX1, tests[googleTestNum].trueX1));
    EXPECT_TRUE(testCondition(testX2, tests[googleTestNum].trueX2));
    EXPECT_TRUE(testCondition(receivedStatus, tests[googleTestNum].trueStatus));
    googleTestNum++;
}

TEST(QUADRATIC_EQUATION, D_EQUAL_NULL_SUCCESS) {
    double testX1 = NAN, testX2 = NAN;
    solveCode receivedStatus = INVALID;

    rootList receivedValues = {};
    rootListInitialize(&receivedValues);

    runGoogleTest(&receivedValues, &testX1, &testX2, &receivedStatus, googleTestNum);

    EXPECT_TRUE(testCondition(testX1, tests[googleTestNum].trueX1));
    EXPECT_TRUE(testCondition(testX2, tests[googleTestNum].trueX2));
    EXPECT_TRUE(testCondition(receivedStatus, tests[googleTestNum].trueStatus));
    googleTestNum++;
}

TEST(QUADRATIC_EQUATION, D_EQUAL_NULL_FAIL) {
    double testX1 = NAN, testX2 = NAN;
    solveCode receivedStatus = INVALID;

    rootList receivedValues = {};
    rootListInitialize(&receivedValues);

    runGoogleTest(&receivedValues, &testX1, &testX2, &receivedStatus, googleTestNum);

    EXPECT_TRUE(testCondition(testX1, tests[googleTestNum].trueX1));
    EXPECT_TRUE(testCondition(testX2, tests[googleTestNum].trueX2));
    EXPECT_TRUE(testCondition(receivedStatus, tests[googleTestNum].trueStatus));
    googleTestNum++;
}

TEST(QUADRATIC_EQUATION, D_GREATER_NULL_SUCCESS) {
    double testX1 = NAN, testX2 = NAN;
    solveCode receivedStatus = INVALID;

    rootList receivedValues = {};
    rootListInitialize(&receivedValues);

    runGoogleTest(&receivedValues, &testX1, &testX2, &receivedStatus, googleTestNum);

    EXPECT_TRUE(testCondition(testX1, tests[googleTestNum].trueX1));
    EXPECT_TRUE(testCondition(testX2, tests[googleTestNum].trueX2));
    EXPECT_TRUE(testCondition(receivedStatus, tests[googleTestNum].trueStatus));
    googleTestNum++;
}

TEST(QUADRATIC_EQUATION, D_GREATER_NULL_FAIL) {
    double testX1 = NAN, testX2 = NAN;
    solveCode receivedStatus = INVALID;

    rootList receivedValues = {};
    rootListInitialize(&receivedValues);

    runGoogleTest(&receivedValues, &testX1, &testX2, &receivedStatus, googleTestNum);

    EXPECT_TRUE(testCondition(testX1, tests[googleTestNum].trueX1));
    EXPECT_TRUE(testCondition(testX2, tests[googleTestNum].trueX2));
    EXPECT_TRUE(testCondition(receivedStatus, tests[googleTestNum].trueStatus));
    googleTestNum++;
}

int runAllGoogleTests(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
