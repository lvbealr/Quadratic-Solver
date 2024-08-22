#include <cmath>

#include "zeroComparison.h"

const double EPS = 1e-05;

/*/ START OF zeroComparison FUNCTION /*/
zeroComparisonCode zeroComparison(double x) {
    if (x < -EPS) {
        return DOUBLE_LESS_EPS;
    }
    else if (fabs(x) <= EPS) {
        return DOUBLE_EQUAL_EPS;
    }
    else {
        return DOUBLE_GREATER_EPS;
    }
}
/*/ END OF zeroComparison FUNCTION /*/