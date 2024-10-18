#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (A != NULL && A->rows == A->columns) {
    double inverse_det = 0.0;
    s21_determinant(A, &inverse_det);
    if (inverse_det != 0) {
      matrix_t res_trans = {0};
      matrix_t tmp_calc = {0};

      s21_calc_complements(A, &tmp_calc);
      s21_transpose(&tmp_calc, &res_trans);
      s21_remove_matrix(&tmp_calc);
      s21_mult_number(&res_trans, (1.0 / inverse_det), result);
      s21_remove_matrix(&res_trans);
    } else {
      error = CALC_ERROR;
    }
  } else {
    error = INCORRECT_MATRIX;
  }

  return error;
}
