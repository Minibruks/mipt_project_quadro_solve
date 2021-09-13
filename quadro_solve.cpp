/**
 * @brief This file contains functions that calculate the number of roots of a quadratic equation
 * and their values, if any exist
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
double DBL_EPSILON = 1e-6;

enum NumOfSolutions {
    INF_SOLUTIONS = -1,
    ZERO_SOLUTIONS = 0,
    ONE_SOLUTION = 1,
    TWO_SOLUTIONS = 2
};

enum TrueFalse {
    TRUE = 1,
    FALSE = 0
};

/**
 * @brief A function that compares double with zero
 * @param term
 * @return TrueFalse
 */

unsigned short zeroComprasion(double term) {
    if (fabs(term) < DBL_EPSILON) {
        return TRUE;
    }
    return FALSE;
}

/**
 * @brief A function that counts the value of x for two specified variables
 * @param x_coef
 * @param free_term
 * @param x the result will be here
 * @return NumOfSolutions
 */

int solveLinear(double x_coef, double free_term, double* x) {
    assert(x != NULL);
    assert(zeroComprasion(x_coef));
    *x = -free_term / x_coef;
    return ONE_SOLUTION;
}

/** \brief A function that returns the number of roots of a square equation and their values
    \version 1.0.0
    \param[in] a x^2 coefficient
    \param[in] b x coefficient
    \param[in] c free term
    \param[out] x1, x2
    \return NumOfSolutions
*/

int solveQuadratic(double a, double b, double c, double* x1, double* x2) {
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (zeroComprasion(a) &&
    zeroComprasion(b) && zeroComprasion(c)) {
        return INF_SOLUTIONS;
    } else if (zeroComprasion(a)) {
        if (zeroComprasion(b)) {
            return ZERO_SOLUTIONS;
        } else {
            solveLinear(b, c, x1);
            *x2 = *x1;
            return 1;
        }
    } else {
        double D = 0;
        D = b * b - 4 * a * c;
        if (D < -DBL_EPSILON) {
            return ZERO_SOLUTIONS;
        }

        double sqrt_D = sqrt(D);
        *x1 = (-b - sqrt_D) / (2 * a);
        *x2 = (-b + sqrt_D) / (2 * a);

        if (zeroComprasion(D)) {
            return ONE_SOLUTION;
        }

        if (!zeroComprasion(D)) {
            return TWO_SOLUTIONS;
        }
    }
    return 0;
}
