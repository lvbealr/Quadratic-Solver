#ifndef additionalElements // TODO rename file
#define additionalElements // TODO  naming case: additionalElements -> ADDITIONAL_ELEMENTS_H_

const int MAX_COUNT = 2;

enum solveCode { // TODO align = symbols
    LINEAR_INF_ROOTS = 0, // a, b, c = 0
    LINEAR_NO_ROOTS = 1, // a, b = 0; c != 0
    LINEAR_ONE_ROOT = 2, // a = 0; b != 0
    QUADRATIC_NO_ROOTS = 3, // D < 0
    QUADRATIC_ONE_ROOT = 4, // D = 0
    QUADRATIC_TWO_ROOTS = 5, // D > 0
    INVALID = 6
};

#endif //additionalElements
