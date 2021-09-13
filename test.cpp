/**
    \brief The program implements a check of the function operation quadro_solve.cpp
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "quadro_solve.cpp"

/**
 * @brief A funtion for reading values from terminal
 * @param a
 * @param b
 * @param c
 * @return Number of input values
 */

int inputVal(double* a, double* b, double* c) {
    int input_count = scanf("%lg %lg %lg", a, b, c);
    return input_count;
}

/**
 * @brief A function that prints number of solutions and their values
 * @param num_of_solutions
 * @param x1
 * @param x2
 * @return Number of solutions and their values
 */
int printNumOfSol(int num_of_solutions, double* x1, double* x2) {
    assert(x1 != NULL);
    assert(x2 != NULL);

    switch (num_of_solutions) {
        case -1:
            printf("Бесконечное множество решений\n");
            break;

        case 0:
            printf("Действительных корней не существует\n");
            break;

        case 1:
            printf("x = %lg\n", *x1);
            break;

        case 2:
            printf("x1 = %lg\nx2 = %lg\n", *x1, *x2);
            break;

        default:
            printf("Ошибка. Не удалось найти значения корней\n");
            return 1;
    }
    return 0;
}

int main() {
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    printf("Введите ТРИ числа:\n");
    while (inputVal(&a, &b, &c) != 3) {
        printf("Вы не ввели число\n");
        scanf("%*s");
    }

    int num_of_solutions = solveQuadratic(a, b, c, &x1, &x2);

    printNumOfSol(num_of_solutions, &x1, &x2);

    return 0;
}
