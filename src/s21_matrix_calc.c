#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (A != NULL && A->rows == A->columns) {
    error = s21_create_matrix(A->columns, A->rows, result);
    if (error == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t minor = {0};
          double minor_det = 0;
          s21_create_matrix(
              A->columns - 1, A->rows - 1,
              &minor);  // создаем матрицу меньше на одну строку и столбец
          s21_deletion(A, &minor, i, j);
          s21_determinant(&minor, &minor_det);
          result->matrix[i][j] = pow(-1, (i + j)) * minor_det;
          s21_remove_matrix(&minor);
        }
      }
    } else {
      s21_remove_matrix(result);
      error = CALC_ERROR;
    }
  } else {
    error = INCORRECT_MATRIX;
  }

  return error;
}