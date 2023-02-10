#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B){
    int CODE = SUCCESS;
    if(A->columns != B->columns || A->rows != B->rows) CODE = FAILURE;
    if(CODE&&A->matrix&&B->matrix) {
        for(int i = 0; i < A->rows; i++) {
            for(int j = 0; j < A->columns; j++) {
                if(A->matrix[i][j] != B->matrix[i][j]) {
                    CODE = FAILURE;
                    break;
                }
            }
            if(CODE == FAILURE) break;
        }
    }
    return CODE;
}