#include <cstdio>
#include <cmath>
#include "additionalElements.h"
#include "struct.h"

const double EPS = 1e-07;

void printResult(rootList *roots) {
    switch (roots->status) {
        case LINEAR_INF_ROOTS:
            printf("Infinitely many solutions"); break;
        case LINEAR_NO_ROOTS:
            printf("No solutions"); break;
        case LINEAR_ONE_ROOT:
            printf("It is linear (non-quadratic) "
                   "equation\nSolutions: "); break;
        case QUADRATIC_NO_ROOTS:
            printf("D < 0: No real solutions"); break;
        case QUADRATIC_ONE_ROOT:
            printf("D = 0\nSolutions: "); break;
        case QUADRATIC_TWO_ROOTS:
            printf("D > 0\nSolutions: "); break;
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
           double const c, rootList *roots) { // TODO assert
                              // TODO think about ouble comparison
    if (fabs(a) <= EPS) { // TODO What if a == NAN or a == INF
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
    printf("Input values of a, b, c coefficients:"); // TODO multiple tries
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Wrong input!");
        return -1;
    }

    Solve(a, b, c, &roots);

    printResult(&roots);

    rootListDestruct(&roots);
    return 0;
}