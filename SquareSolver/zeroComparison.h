#ifndef ZERO_COMPARISON_H_
#define ZERO_COMPARISON_H_

enum zeroComparisonCode {
    DOUBLE_LESS_EPS     = 0, // x < -EPS
    DOUBLE_EQUAL_EPS    = 1, // |x| <= EPS
    DOUBLE_GREATER_EPS  = 2, // x > EPS
};

zeroComparisonCode zeroComparison(double x);

#endif