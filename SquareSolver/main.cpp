#include <cstdio>
#include <cmath>

const double EPS = 1e-07;

enum solveCode {
    LINEAR_INF_ROOTS = 0, // a, b, c = 0
    LINEAR_NO_ROOTS = 1, // a, b = 0; c != 0
    LINEAR_ONE_ROOT = 2, // a = 0; b != 0
    QUADRATIC_NO_ROOTS = 3, // D < 0
    QUADRATIC_ONE_ROOT = 4, // D = 0
    QUADRATIC_TWO_ROOTS = 5 // D > 0
};

void printRoots(solveCode code, double roots[2]) {
    switch (code) {
        case LINEAR_INF_ROOTS: printf("Infinitely many solutions"); break;
        case LINEAR_NO_ROOTS: printf("No solutions"); break;
        case LINEAR_ONE_ROOT: printf("It is linear (non-quadratic) equation\n[0] Solution: x = %lf", roots[0]); break;
        case QUADRATIC_NO_ROOTS: printf("D < 0: no real solutions"); break;
        case QUADRATIC_ONE_ROOT: printf("D = 0\n[0] Solution: x = %lf", roots[0]); break;
        case QUADRATIC_TWO_ROOTS: printf("D > 0\n[0] Solution: x = %lf\n[1] Solution: x = %lf", roots[0], roots[1]); break;
    }
}

solveCode Code;

solveCode linearSolver(double const b, double const c, double roots[2]) {
    if (fabs(b) <= EPS) {
        if (fabs(c) <= EPS) {
            Code = LINEAR_INF_ROOTS;
        }
        else {
            Code = LINEAR_NO_ROOTS;
        }
    }
    else {
        roots[0] = -c/b;
        Code = LINEAR_ONE_ROOT;
    }
    return Code;
}

solveCode squareSolver(double const a, double const b, double const c, double roots[2]) {
    double const discriminant = b*b - 4*a*c;
    if (discriminant < -EPS) {
        Code = QUADRATIC_NO_ROOTS;
    }
    else if (fabs(discriminant) <= EPS) {
        roots[0] = -b/2/a;
        Code = QUADRATIC_ONE_ROOT;
    }
    else {
        roots[0] = (-b + sqrt(discriminant))/2/a; roots[1] = (-b -sqrt(discriminant))/2/a;
        Code = QUADRATIC_TWO_ROOTS;
    }
    return Code;
}

solveCode Solve(double const a, double const b, double const c, double roots[2]) {
    if (fabs(a) <= EPS) {
        Code = linearSolver(b, c, roots);
    }
    else {
        Code = squareSolver(a, b, c, roots);
    }
    return Code;
}

int main(void) {
    double a = NAN, b = NAN, c = NAN;
    double roots[2] = {NAN, NAN};
    printf("Input values of a, b, c coefficients:");
    scanf("%lf %lf %lf", &a, &b, &c);
    solveCode code = Solve(a, b, c, roots);
    printRoots(code, roots);
    return 0;
}