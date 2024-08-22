#include <cmath>

#include "testInput.h"
#include "rootListStruct.h"
#include "solver.h"
#include "solverTest.h"

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