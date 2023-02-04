#include "s21_matrix.h"

void print_matrix(matrix_t A);

int main() {
    matrix_t A;
    s21_create_matrix(1, 1, &A);
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.columns; j++) {
            A.matrix[i][j] = 11;
        }
    }
    //s21_remove_matrix(&A);
    print_matrix(A);

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