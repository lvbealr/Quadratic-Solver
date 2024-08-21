/**
 * \author lvbealr
 * \bug no bugs
 * \version 52.0
 * \warning DeD edition
 */

#include <cstdio>
#include <cassert>
#include <math.h>
#include <cctype>

const double EPS = 1e-07;
const int MAX_ROOT_COUNT = 2;

enum zeroComparisonCode {
    DOUBLE_LESS_EPS     = 0, // x < -EPS
    DOUBLE_EQUAL_EPS    = 1, // |x| <= EPS
    DOUBLE_GREATER_EPS  = 2, // x > EPS
};

enum solveCode {
    LINEAR_INF_ROOTS    = 0, // a, b, c = 0
    LINEAR_NO_ROOTS     = 1, // a, b = 0; c != 0
    LINEAR_ONE_ROOT     = 2, // a = 0; b != 0
    QUADRATIC_NO_ROOTS  = 3, // D < 0
    QUADRATIC_ONE_ROOT  = 4, // D = 0
    QUADRATIC_TWO_ROOTS = 5, // D > 0
    INVALID             = 6
};

/*/ START OF ROOTLIST STRUCT /*/
struct rootList {
    int count = 0;
    double roots[MAX_ROOT_COUNT] = {};
    solveCode status = INVALID;
};

void rootListInitialize(rootList *roots) {
    assert(roots != NULL);

    roots->count = 0;
    for (int index = 0; index < MAX_ROOT_COUNT; index++) {
        roots->roots[index] = NAN;
    }
    roots->status = INVALID;
}

void rootListDestruct(rootList *roots) {
    assert(roots != NULL);

    roots->count = -1;
    for (int index = 0; index < MAX_ROOT_COUNT; index++) {
        roots->roots[index] = NAN;
    }
    roots->status = INVALID;
}

int getRootCount(const rootList *roots) {
    assert(roots != NULL);

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
    assert(roots != NULL);

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

void printResult(rootList *roots) {
    switch (roots->status) {
        case LINEAR_INF_ROOTS:
            printf("Infinitely many solutions");
            break;
        case LINEAR_NO_ROOTS:
            printf("No solutions");
            break;
        case LINEAR_ONE_ROOT:
            printf("It is linear (non-quadratic) "
                   "equation\nSolutions: ");
            break;
        case QUADRATIC_NO_ROOTS:
            printf("D < 0: No real solutions");
            break;
        case QUADRATIC_ONE_ROOT:
            printf("D = 0\nSolutions: ");
            break;
        case QUADRATIC_TWO_ROOTS:
            printf("D > 0\nSolutions: ");
            break;
        case INVALID:
        default:
            break;
    }
    printRoot(roots);
    printf("\n");
}
/*/ END OF ROOTLIST STRUCT /*/

/*/ START OF zeroComparison FUNCTION /*/
zeroComparisonCode zeroComparison(double x) {
    if (x < -EPS) {
        return DOUBLE_LESS_EPS;
    }
    else if (fabs(x) <= EPS) {
        return DOUBLE_EQUAL_EPS;
    }
    else {
        return DOUBLE_GREATER_EPS;
    }
}
/*/ END OF zeroComparison FUNCTION /*/

void linearSolver(double const b, double const c, rootList *roots) {
    if (zeroComparison(b) == DOUBLE_EQUAL_EPS) {
        if (zeroComparison(c) == DOUBLE_EQUAL_EPS) {
            setStatus(roots, LINEAR_INF_ROOTS);
        }
        else {
            setStatus(roots, LINEAR_NO_ROOTS);
        }
    }
    else {
        setStatus(roots, LINEAR_ONE_ROOT);
        pushRoot(roots, -c/b);
    }
}

void squareSolver(double const a, double const b,
                  double const c, rootList *roots) {
    double const discriminant = b*b - 4*a*c;

    zeroComparisonCode code = zeroComparison(discriminant);
    switch (code) {
        case DOUBLE_LESS_EPS:
            setStatus(roots, QUADRATIC_NO_ROOTS);
            break;
        case DOUBLE_EQUAL_EPS:
            setStatus(roots, QUADRATIC_ONE_ROOT);
            pushRoot(roots, -b/2/a);
            break;
        case DOUBLE_GREATER_EPS:
            setStatus(roots, QUADRATIC_TWO_ROOTS);

            double p = -b/2/a;
            double q = sqrt(discriminant)/2/a;

            pushRoot(roots, (p+q));
            pushRoot(roots, (p-q));
            break;
    }
}

void Solve(double const a, double const b,
           double const c, rootList *roots) {

    assert(roots != NULL);

    if (zeroComparison(a) == DOUBLE_EQUAL_EPS) {
        linearSolver(b, c, roots);
    }
    else {
        squareSolver(a, b, c, roots);
    }
}

bool inputCheck(char coefficient_str[100]) {
    bool positiveGreatOneNum = isdigit(coefficient_str[0]);
    bool positiveLessOneNum = coefficient_str[0] == '.' && isdigit(coefficient_str[1]);
    bool negativeGreatOneNum = coefficient_str[0] == '-' && isdigit(coefficient_str[1]);
    bool negativeLessOneNum = coefficient_str[0] == '-' && coefficient_str[1] == '.' && isdigit(coefficient_str[2]);
    return !(positiveGreatOneNum || positiveLessOneNum || negativeGreatOneNum || negativeLessOneNum);
}

bool coefficientInput(char coefficientName, double *coefficient) {
    char coefficient_str[100] = "";

    for (int iter = 0; iter < 3; iter++) {
        printf("Input valid value of coefficient %c:", coefficientName);
        gets(coefficient_str);

        if (inputCheck(coefficient_str)) {
            continue;
        }
        else {
            *coefficient = atof(coefficient_str);
            return true;
        }
    }
    return false;
}

/*/ START OF TESTS /*/
void printTestError(int testNum, double a, double b, double c, double trueX1, double trueX2, double trueRootCount, double testX1, double testX2, double testRootCount) {
    printf("\nERROR. Test %d: a = %lg, b = %lg, c = %lg\nx1 = %lg, x2 = %lg, testRootCount = %lg\n"
           "EXPECTED:\nx1 = %lg, x2 = %lg, rootCount = %lg\n",
           testNum, a, b, c, trueX1, trueX2, trueRootCount,
           testX1, testX2, testRootCount);
}

void printTestSuccess(int testNum) {
    printf("\nTest %d. OK!", testNum);
}

bool testCondition (double x, double y) {
    return (zeroComparison(x - y) == DOUBLE_EQUAL_EPS) || (isnan(x) && isnan(y));
}

void runTest(double a, double b, double c, double trueX1, double trueX2, double trueRootCount) {
    static int testNum = 0;
    testNum++;
    double testX1 = NAN, testX2 = NAN;
    double testRootCount = NAN;
    rootList testRootList;
    rootListInitialize(&testRootList);

    Solve(a, b, c, &testRootList);

    solveCode testStatus = testRootList.status;

    switch (testStatus) {
        case LINEAR_INF_ROOTS:
            testRootCount = NAN;
            break;
        case QUADRATIC_TWO_ROOTS:
            testRootCount = 2;
            testX1 = testRootList.roots[0];
            testX2 = testRootList.roots[1];
            break;
        case LINEAR_ONE_ROOT:
        case QUADRATIC_ONE_ROOT:
            testRootCount = 1;
            testX1 = testRootList.roots[0];
            break;
        case LINEAR_NO_ROOTS:
        case QUADRATIC_NO_ROOTS:
            testRootCount = 0;
            break;
        case INVALID:
        default:
            break;
    }
    if (testCondition(testX1, trueX1) && testCondition(testX2, trueX2) && testCondition(testRootCount, trueRootCount)) {
        printTestSuccess(testNum);
    }
    else {
        printTestError(testNum, a, b, c, trueX1, trueX2, trueRootCount, testX1, testX2, testRootCount);
    }
    rootListDestruct(&testRootList);
}

void runAllTests() {
    runTest(0, 0, 0, NAN, NAN, NAN);
    runTest(1, 2, 1, -1, NAN, 1);
}
/*/ END OF TESTS /*/

int main() {

    /*/ START USER INPUT /*/
//    rootList roots;
//    rootListInitialize(&roots);
//
//    double a = NAN, b = NAN, c = NAN;
//
//    bool flag = false;
//    if (coefficientInput('a', &a)) {
//        if (coefficientInput('b', &b)) {
//            if (coefficientInput('c', &c)) {
//                flag = true;
//            }
//        }
//    }
//
//    if (flag) {
//        Solve(a, b, c, &roots);
//    }
//    else {
//        return -1;
//    }
//
//    printResult(&roots);
//
//    rootListDestruct(&roots);
    /*/ END USER INPUT /*/
    runAllTests();

    return 0;
}