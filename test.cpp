/**
    @brief The program implements a check of the function operation quadro_solve.cpp
    @version 1.0.0
*/

#include "quadro_solve.cpp"

/**
 * @brief A function for reading float values from terminal
 * @version 1.0.0
 * @param a
 * @param b
 * @param c
 * @return Nothing
 */

void readCoefficients(double* a, double* b, double* c) {
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    printf("Введите ТРИ числа:\n");
    while (scanf("%lg %lg %lg", a, b, c) != 3) {
        printf("Вы не ввели число\n");
        scanf("%*s");
    }
}

/**
 * @brief A function that prints number of solutions and their values
 * @version 1.0.0
 * @param num_of_solutions
 * @param x1
 * @param x2
 * @return Number of solutions and their values
 */
int printSolutions(NumOfSolutions num_of_solutions, double x1, double x2) {
    switch (num_of_solutions) {
        case INF_SOLUTIONS:
            printf("Бесконечное множество решений\n");
            break;

        case ZERO_SOLUTIONS:
            printf("Действительных корней не существует\n");
            break;

        case ONE_SOLUTION:
            printf("x = %lg\n", x1);
            break;

        case TWO_SOLUTIONS:
            printf("x1 = %lg\nx2 = %lg\n", x1, x2);
            break;

        default:
            printf("Ошибка. Не удалось найти значения корней\n");
            return 1;
    }
    return 0;
}

int main() {
    double a = 0, b = 0, c = 0;

    readCoefficients(&a, &b, &c);

    double x1 = 0, x2 = 0;
    NumOfSolutions num_of_solutions = solveQuadratic(a, b, c, &x1, &x2);

    printSolutions(num_of_solutions, x1, x2);

    return 0;
}
