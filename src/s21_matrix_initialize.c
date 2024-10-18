#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;

  if (result != NULL && rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));

    if (result->matrix == NULL) {
      error = CALLOC_FAILED;
    } else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          for (int j = 0; j < i; j++) {
            free(result->matrix[j]);
          }
          free(result->matrix);
          error = CALLOC_FAILED;
        }
        error = 0;
      }
    }

  } else {
    error = INCORRECT_MATRIX;
  }

  return error;
}

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
  }
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}
