// TODO COLOR MODULE !!!!!!!!!!!!!

#include <cstdio>
#include <cassert>
#include <math.h>
#include <cctype>

const double EPS = 1e-05;
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

const char *solveCodeString[] = {
        "LINEAR_INF_ROOTS",
        "LINEAR_NO_ROOTS",
        "LINEAR_ONE_ROOT",
        "QUADRATIC_NO_ROOTS",
        "QUADRATIC_ONE_ROOT",
        "QUADRATIC_TWO_ROOTS",
        "INVALID"
};

/*/ ROOTLIST STRUCT /*/
struct rootList {
    int count = 0;
    double roots[MAX_ROOT_COUNT] = {};
    solveCode status = INVALID;
};
/*/ ROOTLIST STRUCT /*/

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

/*/ FUNCTIONS PROTOTYPES /*/
void rootListInitialize(rootList *);
void rootListDestruct(rootList *);
int getRootCount(const rootList *);
bool pushRoot(rootList *, double);
void printRoot(const rootList *);
void setStatus(rootList *, solveCode);
void printResult(rootList *);
zeroComparisonCode zeroComparison(double);
void linearSolver(double, double, rootList *);
void squareSolver(double, double, double, rootList *);
void solve(double, double, double, rootList *);
bool inputCheck(char *);
bool coefficientInput(char, double *);
void printTestError(int, double, double, double, double, double, int, double, double, int);
void printTestSuccess(int);
bool testCondition(double, double);
void runTest(testData, int);
void runAllTests();
int manualMode();
void testMode();
/*/ FUNCTIONS PROTOTYPES /*/

/*/ START OF ROOTLIST STRUCT /*/
void rootListInitialize(rootList *roots) {
    assert(roots != NULL);

    roots->count = 0;
    for (int index = 0; index < MAX_ROOT_COUNT; index++) {
        roots->roots[index] = INFINITY;
    }
    roots->status = INVALID;
}

void rootListDestruct(rootList *roots) {
    assert(roots != NULL);

    roots->count = -1;
    for (int index = 0; index < MAX_ROOT_COUNT; index++) {
        roots->roots[index] = INFINITY;
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
        case DOUBLE_LESS_EPS: {
            setStatus(roots, QUADRATIC_NO_ROOTS);
            break;
        }
        case DOUBLE_EQUAL_EPS: {
            setStatus(roots, QUADRATIC_ONE_ROOT);
            pushRoot(roots, -b / 2 / a);
            break;
        }
        case DOUBLE_GREATER_EPS: {
            setStatus(roots, QUADRATIC_TWO_ROOTS);

            double p = -b / 2 / a;
            double q = sqrt(discriminant) / 2 / a;

            pushRoot(roots, (p - q));
            pushRoot(roots, (p + q));
            break;
        }
        default:
            break;
    }
}

void solve(double const a, double const b,
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
    const size_t INPUT_STRING_SIZE = 100;
    char coefficient_str[INPUT_STRING_SIZE] = "";
    const int TRY_COUNT = 3;

    for (int tryNum = 0; tryNum < TRY_COUNT; tryNum++) {
        printf("Input valid value of coefficient %c:", coefficientName);
        scanf("%100s", coefficient_str);

        if (inputCheck(coefficient_str)) {
            while (getchar() != '\n') {}
            continue;
        }
        else {
            *coefficient = atof(coefficient_str);
            while (getchar() != '\n') {}
            return true;
        }
    }
    return false;
}

/*/ START OF TESTS /*/
void printTestError(int testNum, double a, double b, double c,
                    double trueX1, double trueX2, int trueStatus,
                    double testX1, double testX2, int testStatus) {
    printf("\nTest %d: " "\033[1;31mFAILED! \033[0m"
                         "a = %lg, b = %lg,c = %lg\nx1 = %lg, x2 = %lg, testStatus = %s\n"
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
        testStatus == test.trueStatus           ) {
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
            {0, 0, 0, NAN, NAN, LINEAR_INF_ROOTS},                       // LINEAR_INF_ROOTS --- OK
            {0, 0, 0, 1, 2, LINEAR_INF_ROOTS},                           // LINEAR_INF_ROOTS --- FAILED
            {0, 0, 5, NAN, NAN, LINEAR_NO_ROOTS},                        // LINEAR_NO_ROOTS --- OK
            {0, 0, 3, .6, NAN, LINEAR_NO_ROOTS},                         // LINEAR_NO_ROOTS --- FAILED
            {0, -.6, 3, 5, NAN, LINEAR_ONE_ROOT},                        // LINEAR_ONE_ROOT --- OK
            {0, 8, 3, -9, NAN, LINEAR_ONE_ROOT},                         // LINEAR_ONE_ROOT --- FAILED
            {1, 2, 10, NAN, NAN, QUADRATIC_NO_ROOTS},                    // QUADRATIC_NO_ROOTS --- OK
            {2.5, 999, 2, 3, NAN, QUADRATIC_NO_ROOTS},                   // QUADRATIC_NO_ROOTS --- FAILED
            {1, -4, 4, 2, NAN, QUADRATIC_ONE_ROOT},                      // QUADRATIC_ONE_ROOT --- OK
            {1, 2, 1, 1, NAN, QUADRATIC_ONE_ROOT},                       // QUADRATIC_ONE_ROOT --- FAILED
            {2.5, 9.8, 3.4, -3.535309, -0.384691, QUADRATIC_TWO_ROOTS}, // QUADRATIC_TWO_ROOTS --- OK
            {3, 7.4, -2.37, -2.75, 0.286901, QUADRATIC_TWO_ROOTS}       // QUADRATIC_TWO_ROOTS --- FAILED
    };
    for (int iter = 0; iter < 12; iter++) {
        runTest(tests[iter], iter + 1);
    }
}
/*/ END OF TESTS /*/

/*/ START MODE MENU /*/
int manualMode() {
    rootList roots;
    rootListInitialize(&roots);

    double a = NAN, b = NAN, c = NAN;

    bool flag = false;
    if (coefficientInput('a', &a)) {
        if (coefficientInput('b', &b)) {
            if (coefficientInput('c', &c)) {
                flag = true;
            }
        }
    }

    if (flag) {
        solve(a, b, c, &roots);
    }
    else {
        return -1;
    }

    printResult(&roots);

    rootListDestruct(&roots);
    return 0;
}

void testMode() {
    runAllTests();
}
/*/ END MODE MENU /*/

int main() {
    char mode[1] = "";

    printf("Choose mode: Test Mode (0) / Manual Mode (1). Input (0/1):");
    scanf("%1s", mode);
    while (getchar() != '\n') {}

    if (*mode == '0') {
        testMode();
    }
    else if (*mode == '1') {
        manualMode();
    }
    else {
        printf("Wrong mode input!");
    }

    return 0;
}