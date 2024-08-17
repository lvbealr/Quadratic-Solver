#include <cstdio>
#include <cmath>

const double EPS = 1e-07;

/*/ Start of rootList Struct /*/
const int MAX_COUNT = 2;

struct rootList {
    int count = 0;
    double roots[MAX_COUNT]{};
};

void rootListInitialize(rootList *rL) {
    for (int i = 0; i < MAX_COUNT; i++) {
        rL->roots[i] = NAN;
    }
}
void push(rootList *rL, double pushRoot) {
    if (rL->count < MAX_COUNT) {
        rL->roots[rL->count] = pushRoot;
        rL->count++;
    }
    else {
        printf("Error: rootList is full");
    }
}

double get(rootList *rL) {
    rL->count--;
    return rL->roots[rL->count];
}
/*/ End of rootList struct /*/

enum solveCode {
    LINEAR_INF_ROOTS = 0, // a, b, c = 0
    LINEAR_NO_ROOTS = 1, // a, b = 0; c != 0
    LINEAR_ONE_ROOT = 2, // a = 0; b != 0
    QUADRATIC_NO_ROOTS = 3, // D < 0
    QUADRATIC_ONE_ROOT = 4, // D = 0
    QUADRATIC_TWO_ROOTS = 5 // D > 0
};

void printRoots(solveCode code, rootList rL) {
    switch (code) {
        case LINEAR_INF_ROOTS: printf("Infinitely many solutions"); break;
        case LINEAR_NO_ROOTS: printf("No solutions"); break;
        case LINEAR_ONE_ROOT: printf("It is linear (non-quadratic) equation\n[0] Solution: x = %lf", get(&rL)); break;
        case QUADRATIC_NO_ROOTS: printf("D < 0: no real solutions"); break;
        case QUADRATIC_ONE_ROOT: printf("D = 0\n[0] Solution: x = %lf", get(&rL)); break;
        case QUADRATIC_TWO_ROOTS: printf("D > 0\n[0] Solution: x = %lf\n[1] Solution: x = %lf", get(&rL), get(&rL)); break;
    }
}

solveCode Code;

solveCode linearSolver(double const b, double const c, rootList &rL) {
    if (fabs(b) <= EPS) {
        if (fabs(c) <= EPS) {
            Code = LINEAR_INF_ROOTS;
        }
        else {
            Code = LINEAR_NO_ROOTS;
        }
    }
    else {
        push(&rL, -c/b);
        Code = LINEAR_ONE_ROOT;
    }
    return Code;
}

solveCode squareSolver(double const a, double const b, double const c, rootList &rL) {
    double const discriminant = b*b - 4*a*c;
    if (discriminant < -EPS) {
        Code = QUADRATIC_NO_ROOTS;
    }
    else if (fabs(discriminant) <= EPS) {
        push(&rL, -b/2/a);
        Code = QUADRATIC_ONE_ROOT;
    }
    else {
        push(&rL, (-b + sqrt(discriminant))/2/a);
        push(&rL, (-b -sqrt(discriminant))/2/a);
        Code = QUADRATIC_TWO_ROOTS;
    }
    return Code;
}

solveCode Solve(double const a, double const b, double const c, rootList &rL) {
    if (fabs(a) <= EPS) {
        Code = linearSolver(b, c, rL);
    }
    else {
        Code = squareSolver(a, b, c, rL);
    }
    return Code;
}

int main() {
    rootList rL;
    rootListInitialize(&rL);
    double a = NAN, b = NAN, c = NAN;
    printf("Input values of a, b, c coefficients:");
    scanf("%lf %lf %lf", &a, &b, &c);
    solveCode code = Solve(a, b, c, rL);
    printRoots(code, rL);
    return 0;
}