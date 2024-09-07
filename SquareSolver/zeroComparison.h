#ifndef ZERO_COMPARISON_H_
#define ZERO_COMPARISON_H_

/// @brief Set Of Statuses Of Comparing Double Numbers
enum zeroComparisonCode {
    DOUBLE_LESS_EPS     = 0, // x < -EPS
    DOUBLE_EQUAL_EPS    = 1, // |x| <= EPS
    DOUBLE_GREATER_EPS  = 2, // x > EPS
};

/**
 * @brief Compare Two Double Numbers
 * 
 * @param [in] x 
 * @return zeroComparisonCode Result Of Comparison Of Double Number With Zero
 */
zeroComparisonCode zeroComparison(double x);

#endif