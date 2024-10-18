
#include "s21_matrix.h"

// функция копирование матрицы
void s21_copy_matrix(matrix_t *A, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j];
    }
  }
}

void s21_gauss(matrix_t *temp, double *result) {
  int sign = 1;
  double det = 1.0;
  for (int i = 0; i < temp->rows; i++) {
    // На шаге i если элемент на диагонали (temp->matrix[i][i]) равен 0, то
    // меняем строки местами
    if (temp->matrix[i][i] == 0) {
      int swap_row = i + 1;
      while (swap_row < temp->rows && temp->matrix[swap_row][i] == 0) {
        swap_row++;
      }
      // если все элементы в строке равны 0, то матрица вырожденная
      if (swap_row == temp->rows) {
        *result = 0;
        s21_remove_matrix(temp);
        det = 0.0;
        break;
      }
      // меняем строки местами
      double *tmp = temp->matrix[i];
      temp->matrix[i] = temp->matrix[swap_row];
      temp->matrix[swap_row] = tmp;
      // Меняем знак определителя
      sign = -sign;
    }
    // приводим строку к верхнетреугольному виду
    for (int j = i + 1; j < temp->rows; j++) {
      // вычисляем коэффициент
      double coeff = temp->matrix[j][i] / temp->matrix[i][i];
      // вычитаем коэффициент из строк
      for (int k = i; k < temp->columns; k++) {
        temp->matrix[j][k] -= coeff * temp->matrix[i][k];
      }
    }

    det *= temp->matrix[i][i];
  }
  *result = det * sign;
}

void s21_deletion(matrix_t *A, matrix_t *result, int i_row, int j_col) {
  int minor_row = 0, minor_col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == i_row) continue;  // Пропускаем удаленную строку
    minor_col = 0;             // зануляем номер столбца
    for (int j = 0; j < A->columns; j++) {
      if (j == j_col) continue;  // Пропускаем удаленный столбец
      result->matrix[minor_row][minor_col] = A->matrix[i][j];
      minor_col++;
    }
    minor_row++;
  }
}
