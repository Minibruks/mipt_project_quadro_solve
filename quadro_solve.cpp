#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#define SMALL_DOUBLE_FOR_CMP_WITH_ZERO 1e-6

/** \brief A function that returns the number of roots of a square equation and their values
    \version 1.0.0
    \param[in] a x^2 coefficient
    \param[in] b x coefficient
    \param[in] c free term
    \param[out] x1, x2
    \return -1 - infinite number of solutions, 0 - no roots, 1 - one root, 2 - two roots
 */

enum num_of_solves {
    UNDEFINED_SOLVES = -1,
    ZERO_SOLVES = 0,
    ONE_SOLVE = 1,
    TWO_SOLVES = 2
};

void linearSolve(double b, double c, double* x) {
    *x = -c / b;
}

int quadroSolve(double a, double b, double c, double* x1, double* x2) {
    assert(x1 != NULL);
    assert(x2 != NULL);

    if (fabs(a) < SMALL_DOUBLE_FOR_CMP_WITH_ZERO &&
    fabs(b) < SMALL_DOUBLE_FOR_CMP_WITH_ZERO && fabs(c) < SMALL_DOUBLE_FOR_CMP_WITH_ZERO) {
        return UNDEFINED_SOLVES;
    } else if (fabs(a) < SMALL_DOUBLE_FOR_CMP_WITH_ZERO) {
        if (fabs(b) < SMALL_DOUBLE_FOR_CMP_WITH_ZERO) {
            return ZERO_SOLVES;
        } else {
            linearSolve(b, c, x1);
            *x2 = *x1;
            return 1;
        }
    } else {
        double D = 0;
        D = b * b - 4 * a * c;
        if (D < 0) {
            return ZERO_SOLVES;
        }

        double sqrt_D = sqrt(D);
        *x1 = (-b - sqrt_D) / (2 * a);
        *x2 = (-b + sqrt_D) / (2 * a);

        if (fabs(D) < SMALL_DOUBLE_FOR_CMP_WITH_ZERO) {
            return ONE_SOLVE;
        }

        if (D > 0) {
            assert(x1 != x2);
            return TWO_SOLVES;
        }
    }
    return 0;
}