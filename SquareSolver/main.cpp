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

void rootListInitialize(rootList *rL) {
    int count = 0;
    for (int i = 0; i < MAX_COUNT; i++) {
        rL->roots[i] = NAN;
    }
    rL->status = INVALID;
}

void rootListDestruct(rootList *rL) {
    int count = MAX_COUNT;
    for (int i = 0; i < MAX_COUNT; i++) {
        rL->roots[i] = NAN;
    }
    rL->status = INVALID;
}

int getRootCount(rootList *rL) {
    switch (rL->status) {
        case LINEAR_ONE_ROOT:
        case QUADRATIC_ONE_ROOT: return 1;
        case QUADRATIC_TWO_ROOTS: return 2;
        case LINEAR_NO_ROOTS:
        case QUADRATIC_NO_ROOTS:
        case LINEAR_INF_ROOTS:
        case INVALID:
        default: return 0;
    }
}

bool pushRoot(rootList *rL, double Root) {
    if ((0 <= rL->count) && (rL->count < getRootCount(rL))) {
        rL->roots[rL->count] = Root;
        rL->count++;
        return true;
    }
    return false;
}

void printRoot(rootList *rL) {
    int cnt = getRootCount(rL);
    for (int i = 0; i < cnt; i++) {
        printf("%lf\t", rL->roots[i]);
    }
}

void setStatus(rootList *rL, solveCode Status) {
    rL->status = Status;
}
/*/ End of rootList struct /*/

void printResult(rootList *rL) {
    switch (rL->status) {
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
    printRoot(rL);
    printf("\n");
}

void linearSolver(double const b, double const c, rootList *rL) {
    if (fabs(b) <= EPS) {
        if (fabs(c) <= EPS) {
            setStatus(rL, LINEAR_INF_ROOTS);
        }
        else {
            setStatus(rL, LINEAR_NO_ROOTS);
        }
    }
    else {
        setStatus(rL, LINEAR_ONE_ROOT);
        pushRoot(rL, -c/b);
    }
}

void squareSolver(double const a, double const b,
                  double const c, rootList *rL) {
    double const discriminant = b*b - 4*a*c;
    if (discriminant < -EPS) {
        setStatus(rL, QUADRATIC_NO_ROOTS);
    }
    else if (fabs(discriminant) <= EPS) {
        setStatus(rL, QUADRATIC_ONE_ROOT);
        pushRoot(rL, -b/2/a);
    }
    else {
        setStatus(rL, QUADRATIC_TWO_ROOTS);
        double p = -b/2/a;
        double q = sqrt(discriminant)/2/a;
        pushRoot(rL, (p+q));
        pushRoot(rL, (p-q));
    }
}

void Solve(double const a, double const b,
           double const c, rootList *rL) {
    if (fabs(a) <= EPS) {
        linearSolver(b, c, rL);
    }
    else {
        squareSolver(a, b, c, rL);
    }
}

int main() {
    rootList rL;
    rootListInitialize(&rL);

    double a = NAN, b = NAN, c = NAN;
    printf("Input values of a, b, c coefficients:");
    scanf("%lf %lf %lf", &a, &b, &c);

    Solve(a, b, c, &rL);

    printResult(&rL);

    rootListDestruct(&rL);
    return 0;
}