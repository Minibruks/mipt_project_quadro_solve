#include "quadro_solve_lib.h"

short cmp(double a, double b) {
    if (fabs(a - b) < DBL_EPSILON) {
        return 0;
    } else if (a - b > DBL_EPSILON) {
        return 1;
    }
    return -1;
}

int solveLinear(double x_coef, double free_term, double* x) {
    assert(x != NULL);
    if (!cmp(x_coef)) {
        return INF_SOLUTIONS;
    }
    *x = -free_term / x_coef;
    return ONE_SOLUTION;
}

NumOfSolutions solveQuadratic(double a, double b, double c, double* x1, double* x2) {
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (!cmp(a) && !cmp(b) && !cmp(c)) {
        return INF_SOLUTIONS;
    } else if (!cmp(a)) {
        if (!cmp(b)) {
            return ZERO_SOLUTIONS;
        } else {
            solveLinear(b, c, x1);
            *x2 = *x1;
            return ONE_SOLUTION;
        }
    } else {
        double D = b * b - 4 * a * c;

        if (cmp(D) == -1) {
            return ZERO_SOLUTIONS;
        }

        double sqrt_D = sqrt(D);
        *x1 = (-b - sqrt_D) / (2 * a);
        *x2 = (-b + sqrt_D) / (2 * a);

        if (!cmp(D)) {
            return ONE_SOLUTION;
        }

        if (cmp(D)) {
            return TWO_SOLUTIONS;
        }
    }
}
