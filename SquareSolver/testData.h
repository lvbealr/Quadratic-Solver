#include <cmath>
#include "rootListStruct.h"

// TODO TRUE TESTS

/// @brief List Of Test Data
const testData tests[] = {
            {0,   0,   0,     NAN,       NAN,       LINEAR_INF_ROOTS},       // LINEAR_INF_ROOTS    --- OK
            {0,   0,   5,     NAN,       NAN,       LINEAR_NO_ROOTS},        // LINEAR_NO_ROOTS     --- OK
            {0,   -.6, 3,     5,         NAN,       LINEAR_ONE_ROOT},        // LINEAR_ONE_ROOT     --- OK
            {0,   5,   3,     -.6,       NAN,       LINEAR_ONE_ROOT},        // LINEAR_ONE_ROOT     --- OK
            {1,   2,   10,    NAN,       NAN,       QUADRATIC_NO_ROOTS},     // QUADRATIC_NO_ROOTS  --- OK
            {2.5, 1,   2,     NAN,       NAN,       QUADRATIC_NO_ROOTS},     // QUADRATIC_NO_ROOTS  --- OK
            {1,   -4,  4,     2,         NAN,       QUADRATIC_ONE_ROOT},     // QUADRATIC_ONE_ROOT  --- OK
            {1,   2,   1,     -1,        NAN,       QUADRATIC_ONE_ROOT},     // QUADRATIC_ONE_ROOT  --- OK
            {2.5, 9.8, 3.4,   -3.535309, -0.384691, QUADRATIC_TWO_ROOTS},    // QUADRATIC_TWO_ROOTS --- OK
            {3,   7.4, -2.37, -2.75357,  0.286901,  QUADRATIC_TWO_ROOTS}     // QUADRATIC_TWO_ROOTS --- OK
    };
