#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "quadro_solve.cpp"

struct simple_test {
    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;
    int num_of_sol = 0;
};

void unit_tests(simple_test simpleTest[], int num_of_tests = 0) {
    for (int i = 0; i < num_of_tests; i++) {
        NumOfSolutions num_of_solutions = solveQuadratic(simpleTest[i].a, simpleTest[i].b, simpleTest[i].c, &simpleTest[i].x1, &simpleTest[i].x2);
        if (num_of_solutions == simpleTest[i].num_of_sol) {
            printf("Test %d: OK\n", i + 1);
        } else {
            if (num_of_solutions == -1) {
                printf("ERROR\nInput params: %lf, %lf, %lf\nExpected: %d solution(s)\nGot: infinite number of solutions\n", simpleTest[i].a, simpleTest[i].b, simpleTest[i].c, simpleTest[i].num_of_sol);
            } else {
                printf("ERROR\nInput params: %lf, %lf, %lf\nExpected: %d solution(s)\nGot: %d solution(s)\n", simpleTest[i].a, simpleTest[i].b, simpleTest[i].c, simpleTest[i].num_of_sol, num_of_solutions);
            }
        }
    }
}

int main() {
    simple_test simpleTest[] = {{1, -4, 4, 2, 2, ONE_SOLUTION}, {2, 0, -5, -1.58, 1.58, TWO_SOLUTIONS},
                                {4, 0, 4, NULL, NULL, ZERO_SOLUTIONS}, {0, 0, 0, 1, 2, INF_SOLUTIONS},
                                {3, 0, -27, -3, 3, TWO_SOLUTIONS}};
    int num_of_tests = 5;

    unit_tests(simpleTest, num_of_tests);

    return 0;
}
