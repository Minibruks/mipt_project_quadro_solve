/**
 * @brief This file contains functions that calculate the number of roots of a quadratic equation
 * and their values, if any exist
 * @version 1.0.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <float.h>

enum NumOfSolutions {
    INF_SOLUTIONS = -1,
    ZERO_SOLUTIONS = 0,
    ONE_SOLUTION = 1,
    TWO_SOLUTIONS = 2
};

/**
 * @brief A function that compares doubles
 * @version 1.0.0
 * @param term
 * @return TrueFalse
 */
short cmp(double a = 0, double b = 0);

/**
 * @brief A function that solves a linear equation
 * @version 1.0.0
 * @param x_coef
 * @param free_term
 * @param x the solution will be here
 * @return Number of solutions
 */
int solveLinear(double x_coef, double free_term, double* x);

/** @brief A function that solves quadratic equation
    @version 1.0.0
    @param[in] a x^2 coefficient
    @param[in] b x coefficient
    @param[in] c free term
    @param[out] x1, x2
    @return NumOfSolutions
*/
NumOfSolutions solveQuadratic(double a, double b, double c, double* x1, double* x2);
