#include <cmath>
#include <cstdio>

#include "rootListStruct.h"
#include "solver.h"
#include "solverTest.h"
#include "coefficientInput.h"

/*/ START MODE MENU /*/
int manualMode() {
    double a = NAN, b = NAN, c = NAN;

    rootList roots = {};
    rootListInitialize(&roots);

    bool validCoefficientInput = coefficientInput(&a, &b, &c);

    if (validCoefficientInput) {
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