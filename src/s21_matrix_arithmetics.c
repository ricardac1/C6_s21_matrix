#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (A != NULL && B != NULL && A->columns == B->columns &&
      A->rows == B->rows) {
    error = s21_create_matrix(A->rows, A->columns, result);

    if (error == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    } else {
      s21_remove_matrix(result);
      error = CALC_ERROR;
    }
  } else {
    error = CALC_ERROR;
  }
  return error;
}
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (A != NULL && B != NULL && A->columns == B->columns &&
      A->rows == B->rows) {
    error = s21_create_matrix(A->rows, A->columns, result);
    if (error == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    } else {
      s21_remove_matrix(result);
      error = CALC_ERROR;
    }
  } else {
    error = CALC_ERROR;
  }
  return error;
}
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = 0;
  if (A != NULL) {
    error = s21_create_matrix(A->rows, A->columns, result);
    if (error == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    } else {
      s21_remove_matrix(result);
      error = CALC_ERROR;
    }
  } else {
    error = CALC_ERROR;
  }

  return error;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (result == NULL || A == NULL || B == NULL || A->matrix == NULL ||
      B->matrix == NULL || (A->columns != B->rows)) {
    error = CALC_ERROR;
  } else {
    error = s21_create_matrix(A->rows, B->columns, result);
    if (error == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < A->columns; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    }
  }
  return error;
}