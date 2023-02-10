#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    int CODE = OK;
    if(A->columns != B->columns || A->rows != B->rows) CODE = CALCULATION_ERROR;
    if(CODE==OK) {
        for(int i = 0; i < A->rows; i++) {
            for(int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            }
        }
    }
    return CODE;
}