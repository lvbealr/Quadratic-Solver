#include <cstdio>
#include <cmath>

const double EPS = 1e-07;
const int MAX_COUNT = 2;

enum solveCode {
    LINEAR_INF_ROOTS = 0, // a, b, c = 0
    LINEAR_NO_ROOTS = 1, // a, b = 0; c != 0
    LINEAR_ONE_ROOT = 2, // a = 0; b != 0
    QUADRATIC_NO_ROOTS = 3, // D < 0
    QUADRATIC_ONE_ROOT = 4, // D = 0
    QUADRATIC_TWO_ROOTS = 5, // D > 0
    INVALID = 6
};

/*/ Start of rootList Struct /*/
struct rootList {
    int count = 0;
    double roots[MAX_COUNT] = {};
    solveCode status = INVALID;
};

void rootListInitialize(rootList *roots) {
    roots->count = 0;
    for (int i = 0; i < MAX_COUNT; i++) {
        roots->roots[i] = NAN;
    }
    roots->status = INVALID;
}

void rootListDestruct(rootList *roots) {
    roots->count = MAX_COUNT;
    for (int i = 0; i < MAX_COUNT; i++) {
        roots->roots[i] = NAN;
    }
    roots->status = INVALID;
}

int getRootCount(rootList *roots) {
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

bool pushRoot(rootList *roots, double Root) {
    if ((roots->count < 0) && (roots->count >= getRootCount(roots))) {
        return false;
    }
    roots->roots[roots->count] = Root;
    roots->count++;
    return true;
}

void printRoot(rootList *roots) {
    int rootCount = getRootCount(roots);
    for (int i = 0; i < rootCount; i++) {
        printf("%lf\t", roots->roots[i]);
    }
}

void setStatus(rootList *roots, solveCode status) {
    roots->status = status;
}
/*/ End of rootList struct /*/

void printResult(rootList *roots) {
    switch (roots->status) {
        case LINEAR_INF_ROOTS: printf("Infinitely many solutions"); break;
        case LINEAR_NO_ROOTS: printf("No solutions"); break;
        case LINEAR_ONE_ROOT: printf("It is linear (non-quadratic) "
                                     "equation\nSolutions: "); break;
        case QUADRATIC_NO_ROOTS: printf("D < 0: No real solutions"); break;
        case QUADRATIC_ONE_ROOT: printf("D = 0\nSolutions: "); break;
        case QUADRATIC_TWO_ROOTS: printf("D > 0\nSolutions: "); break;
        case INVALID:
        default:
        break;
    }
    printRoot(roots);
    printf("\n");
}

void linearSolver(double const b, double const c, rootList *roots) {
    if (fabs(b) <= EPS) {
        if (fabs(c) <= EPS) {
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
    if (discriminant < -EPS) {
        setStatus(roots, QUADRATIC_NO_ROOTS);
    }
    else if (fabs(discriminant) <= EPS) {
        setStatus(roots, QUADRATIC_ONE_ROOT);
        pushRoot(roots, -b/2/a);
    }
    else {
        setStatus(roots, QUADRATIC_TWO_ROOTS);
        double p = -b/2/a;
        double q = sqrt(discriminant)/2/a;
        pushRoot(roots, (p+q));
        pushRoot(roots, (p-q));
    }
}

void Solve(double const a, double const b,
           double const c, rootList *roots) {
    if (fabs(a) <= EPS) {
        linearSolver(b, c, roots);
    }
    else {
        squareSolver(a, b, c, roots);
    }
}

int main() {
    rootList roots;
    rootListInitialize(&roots);

    double a = NAN, b = NAN, c = NAN;
    printf("Input values of a, b, c coefficients:");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Wrong input!");
        return -1;
    }

    Solve(a, b, c, &roots);

    printResult(&roots);

    rootListDestruct(&roots);
    return 0;
}