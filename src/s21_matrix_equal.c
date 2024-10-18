#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;

  if (A != NULL && B != NULL && A->columns == B->columns &&
      A->rows == B->rows) {
    for (int i = 0; i < A->rows && res; i++) {
      for (int j = 0; j < A->columns && res; j++) {
        if (round(A->matrix[i][j] * pow(10, 7)) !=
            round(B->matrix[i][j] * pow(10, 7))) {
          res = FAILURE;
        }
      }
    }
  } else {
    res = FAILURE;
  }
  return res;
}