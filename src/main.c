#include "s21_matrix.h"

void print_matrix(matrix_t A);

int main() {
    matrix_t A, B, result;
    s21_create_matrix(10, 11, &A);
    s21_create_matrix(10, 11, &B);
    s21_create_matrix(10, 11, &result);
    for (int i = 0; i < B.rows; i++) {
        for (int j = 0; j < B.columns; j++) {
             A.matrix[i][j] = 11;
             B.matrix[i][j] = 11;
        }
    }
    s21_sum_matrix(&A, &B, &result);
    print_matrix(result);

    return 0;
}

void print_matrix(matrix_t A) {
    printf("rows: %d\n", A.rows);
    printf("columns: %d\n", A.columns);
    for(int i = 0; i < A.rows; i++) {
        for(int j = 0; j < A.columns; j++) {
            printf("%-10.1lf", A.matrix[i][j]);
        }
        printf("\n");
    }
}