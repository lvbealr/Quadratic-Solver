#include <cmath>
#include <cstdio>

#include "rootListStruct.h"
#include "solver.h"
#include "solverTest.h"
#include "coefficientInput.h"
#include "coefficientListStruct.h"
#include "googleTests.h"
#include "menu.h"

/*/ START MODE MENU /*/
void manualMode() {
    
    rootList roots = {};
    rootListInitialize(&roots);

    coefficientList coefficients = {};
    coefficientListInitialize(&coefficients);

    int validCoefficientInput = coefficientInput(&coefficients);
     
    if (!validCoefficientInput) {
        solve(&coefficients, &roots);
    }

    printResult(&roots);

    rootListDestruct(&roots);
    coefficientListDestruct(&coefficients);
}

void testMode() {
    runAllTests();
}

void googleTestMode(int argc, char *argv[]) {
    runAllGoogleTests(argc, argv);
}
/*/ END MODE MENU /*/