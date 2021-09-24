#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "quadro_solve.cpp"

struct QuadEquationTest {
    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;
    int num_of_sol = 0;
};

/**
 * @brief A function for testing quadro_solve.cpp
 * @version 1.0.0
 * @param test_example[]
 * @param num_of_tests
 */
void unitTests(QuadEquationTest test_example[], int num_of_tests = 0) {
    for (int i = 0; i < num_of_tests; i++) {
        NumOfSolutions num_of_solutions = solveQuadratic(test_example[i].a, test_example[i].b, test_example[i].c, &test_example[i].x1, &test_example[i].x2);
        if (num_of_solutions == test_example[i].num_of_sol) {
            printf("Test %d: OK\n", i + 1);
        } else {
            if (num_of_solutions == -1) {
                printf("ERROR\nInput params: %lf, %lf, %lf\nExpected: %d solution(s)\nGot: infinite number of solutions\n", test_example[i].a, test_example[i].b, test_example[i].c, test_example[i].num_of_sol);
            } else {
                printf("ERROR\nInput params: %lf, %lf, %lf\nExpected: %d solution(s)\nGot: %d solution(s)\n", test_example[i].a, test_example[i].b, test_example[i].c, test_example[i].num_of_sol, num_of_solutions);
            }
        }
    }
}

int main() {
    QuadEquationTest test_example[] = {{1, -4, 4, 2, 2, ONE_SOLUTION}, {2, 0, -5, -1.58, 1.58, TWO_SOLUTIONS},
                                {4, 0, 4, NULL, NULL, ZERO_SOLUTIONS}, {0, 0, 0, 1, 2, INF_SOLUTIONS},
                                {3, 0, -27, -3, 3, TWO_SOLUTIONS}};
    int num_of_tests = 5;

    unitTests(test_example, num_of_tests);

    return 0;
}
