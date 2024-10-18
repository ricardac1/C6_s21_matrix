#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error = 0;
  if (A != NULL && A->columns == A->rows) {
    matrix_t temp = {0};
    double det_res = 1.0;

    error = s21_create_matrix(A->rows, A->columns, &temp);
    // приводим матрицу temp к верхнетреугольному виду
    if (error == 0) {
      // копируем во временную матрицу
      s21_copy_matrix(A, &temp);
      s21_gauss(&temp, &det_res);
      *result = det_res;

    } else {
      error = INCORRECT_MATRIX;
    }
    s21_remove_matrix(&temp);
  } else {
    error = INCORRECT_MATRIX;
  }

  return error;
}
